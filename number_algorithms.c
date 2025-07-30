#include <stdio.h>



int search(int arr[], int size) {
    int exit = 0;
    int target;
    
    while (exit != 1)
    {
        int result = -1;
        printf("get a user number: ");
        scanf("%d", &target);


        
        for(int i = 0; i < size; i++) {
            if(arr[i] == target) {
                result = i; 
            }
        }

        if(result != -1) {
            printf("Number %d found at index %d.\n", target, result);
        } else {
            printf("Number %d not found.\n", target);
        }

        printf("To continue \n");
        printf("Enter 1 to exit or other number to coninue: ");
        scanf("%d", &exit);  
    }
   
   return 0;
}

int main() {
    int numbers[] = {5, 10, 15, 20, 25, 30};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    search(numbers, size);
   
    return 0;
}



// int search(int* nums, int numsSize, int target) {


//       int left = 0;
//       int right = numsSize - 1;

//     while (left <= right) {
//         int mid = left + (right - left) / 2;  // avoids overflow

//         if (nums[mid] == target)
//             return mid;
//         else if (nums[mid] < target)
//             left = mid + 1;
//         else
//             right = mid - 1;
//     }

//     return -1;  // not found
// }


// int arr[] = {5, 3, 8, 2};
// int min = arr[0];
// for (int i = 1; i < 4; i++) {
//     if (arr[i] < min) {
//         min = arr[i];
//     }
// }
// printf("%d", min); 


#include <stdio.h>

int main() {
    char word[] = "educare";  // string stored as an array
    int i = 0;

    while (word[i] != '\0') {  // loop until end of string
        printf("%c\n", word[i]);
        i++;
    }

    return 0;
}

// 200 / 16 = 12 remainder 8
// 12 / 16 = 0 remainder 12

// Decimal: 200
// Hexadecimal: 88 = OxC8

// 0x256   = (2 × 16^2) + (5 × 16^1) + (6 × 16^0)
//         = (2 × 256) + (5 × 16) + (6 × 1)
//         = 512 + 80 + 6
// Decimal = 598

