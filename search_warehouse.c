#include <stdio.h>
#include <string.h>

#define MAX_ID_LENGTH 50

int main() {
    int n;
    printf("Enter number of product boxes: ");
    scanf("%d", &n);
    getchar(); // Consume newline left by scanf

    char productIds[n][MAX_ID_LENGTH];
    char product[MAX_ID_LENGTH];

    // Input product IDs
    for (int i = 0; i < n; i++) {
        printf("Box %d: ", i+1);
        fgets(productIds[i], sizeof(productIds[i]), stdin);
        productIds[i][strcspn(productIds[i], "\n")] = '\0'; // Remove newline
    }

    // Input product ID to search for
    printf("Enter product ID to search: ");
    fgets(product, sizeof(product), stdin);
    product[strcspn(product, "\n")] = '\0';

    // Search for matches
    int found = 0;
    printf("Product ID \"%s\" found at box indices: ", product);
    for (int i = 0; i < n; i++) {
        if (strcmp(productIds[i], product) == 0) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }

    printf("\n");
    return 0;
}






