#include <stdio.h>

int main() {
    int warehouse_size;
    int exit = 0;
    printf("Enter the number of items in the warehouse: ");
    scanf("%d", &warehouse_size);

    if (warehouse_size <= 0) {
        printf("Warehouse size must be a positive integer.\n");
        return 1;
    }

    int warehouse_ids[warehouse_size];

    printf("Enter the item IDs for the warehouse:\n");
    for (int i = 0; i < warehouse_size; i++) {
        printf("Item ID at position %d: ", i);
        scanf("%d", &warehouse_ids[i]);
    }

    int search_id;
    while (exit != 1)
    {
        printf("\nEnter the item ID to search for: ");
        scanf("%d", &search_id);

        printf("\nSearching for item ID %d...\n", search_id);

        int found_count = 0;
        for (int i = 0; i < warehouse_size; i++) {
            if (warehouse_ids[i] == search_id) {
                printf("Match found at position: %d\n", i);
                found_count++;
            }
        }

        if (found_count == 0) {
            printf("No matches found for item ID %d.\n", search_id);
        } else {
            printf("Total matches found: %d\n", found_count);
        }
        
        printf("Would you like to search again?");
        printf("Enter 1 to exist or enter any other number to continue:");
        scanf("%d", &exit);
    }

    return 0;
}






// #include <stdio.h>

// #define MAX_ITEMS 50

// int main() {
//     int warehouse[MAX_ITEMS];
//     int n, searchID;
    
//     // Input: Number of items
//     printf("Enter number of items in warehouse (max %d): ", MAX_ITEMS);
//     scanf("%d", &n);

//     if (n < 1 || n > MAX_ITEMS) {
//         printf("Invalid number of items.\n");
//         return 1;
//     }

//     // Input: IDs
//     printf("Enter %d item IDs:\n", n);
//     for (int i = 0; i < n; i++) {
//         printf("ID at position %d: ", i);
//         scanf("%d", &warehouse[i]);
//     }

//     // Input: ID to search
//     printf("Enter ID to search for: ");
//     scanf("%d", &searchID);

//     // Search and output results
//     int found = 0;
//     printf("ID %d found at positions: ", searchID);
//     for (int i = 0; i < n; i++) {
//         if (warehouse[i] == searchID) {
//             printf("%d ", i);
//             found = 1;
//         }
//     }

//     if (!found) {
//         printf("None");
//     }

//     printf("\n");

//     return 0;
// }







// #include <stdio.h> 
// #include <stdlib.h> 


// int main(void){

//     // Loop for 4 rows
//     for (int i = 0; i < 4; i++) {
//         // Loop for 4 columns
//         for (int j = 0; j < 4; j++) {
//             printf("#");
//         }
//         printf("\n"); // Newline after each row
//     }

//     return 0;
    
// }

