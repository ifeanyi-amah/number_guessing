#include <stdio.h> 
#include <stdlib.h> 
int main(int argc, char *argv[])
{
     int data[] = {10, 20, 30, 40, 50};

     int total_size = sizeof(data) / sizeof(data[0]);

   // Print the index of a number if found
     if (argc < 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[1]); 

     // Search for the number
    for (int i = 0; i < total_size; i++) {
        if (data[i] == key) {
            printf("Number %d found at index %d\n", key, i);
            return 0;
        }
    }

     printf("Number %d not found\n", key);

    return 0;
}