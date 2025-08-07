#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1) // Ensure no padding
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1, bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGBTRIPLE;

void apply_grayscale(RGBTRIPLE *pixel) {
    unsigned char gray = (pixel->red + pixel->green + pixel->blue) / 3;
    pixel->red = pixel->green = pixel->blue = gray;
}

void apply_invert(RGBTRIPLE *pixel) {
    pixel->red = 255 - pixel->red;
    pixel->green = 255 - pixel->green;
    pixel->blue = 255 - pixel->blue;
}

void apply_mirror(RGBTRIPLE *row, int width) {
    for (int i = 0; i < width / 2; ++i) {
        RGBTRIPLE tmp = row[i];
        row[i] = row[width - i - 1];
        row[width - i - 1] = tmp;
    }
}

int main() {
    char input_file[100], output_file[100], mode[10];
    printf("Enter input BMP file: ");
    scanf("%s", input_file);
    printf("Enter output BMP file: ");
    scanf("%s", output_file);
    printf("Choose mode (gray, invert, mirror): ");
    scanf("%s", mode);

    FILE *in = fopen(input_file, "rb");
    if (!in) {
        perror("Error opening input file");
        return 1;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(fileHeader), 1, in);
    fread(&infoHeader, sizeof(infoHeader), 1, in);

    if (fileHeader.bfType != 0x4D42 || infoHeader.biBitCount != 24) {
        printf("Only 24-bit BMP files are supported.\n");
        fclose(in);
        return 1;
    }

    int width = infoHeader.biWidth;
    int height = abs(infoHeader.biHeight);
    int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

    RGBTRIPLE **pixels = malloc(height * sizeof(RGBTRIPLE *));
    for (int i = 0; i < height; i++)
        pixels[i] = malloc(width * sizeof(RGBTRIPLE));

    fseek(in, fileHeader.bfOffBits, SEEK_SET);

    for (int i = 0; i < height; i++) {
        fread(pixels[i], sizeof(RGBTRIPLE), width, in);
        fseek(in, padding, SEEK_CUR);
    }
    fclose(in);

    // Apply selected filter
    for (int i = 0; i < height; i++) {
        if (strcmp(mode, "gray") == 0) {
            for (int j = 0; j < width; j++)
                apply_grayscale(&pixels[i][j]);
        } else if (strcmp(mode, "invert") == 0) {
            for (int j = 0; j < width; j++)
                apply_invert(&pixels[i][j]);
        } else if (strcmp(mode, "mirror") == 0) {
            apply_mirror(pixels[i], width);
        } else {
            printf("Unknown mode.\n");
            return 1;
        }
    }

    FILE *out = fopen(output_file, "wb");
    if (!out) {
        perror("Error opening output file");
        return 1;
    }

    fwrite(&fileHeader, sizeof(fileHeader), 1, out);
    fwrite(&infoHeader, sizeof(infoHeader), 1, out);

    for (int i = 0; i < height; i++) {
        fwrite(pixels[i], sizeof(RGBTRIPLE), width, out);
        for (int j = 0; j < padding; j++)
            fputc(0x00, out);
        free(pixels[i]); // Free row after writing
    }
    free(pixels); // Free row pointers

    fclose(out);
    printf("Done! %s image saved to %s\n", mode, output_file);
    return 0;
}