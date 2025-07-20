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


