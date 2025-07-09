#include <stdio.h> 
#include <stdlib.h> 
int main(int count, char** argv[]) 
{ 
    if (count < 2)
    { 
        printf("Usage: %s number1 number2 number3 ....\n", (char*)argv[0]); 
        return 1; 
    } 
    int sum; 
    for (int i = 1; i < count; i++) 
    { 
        sum += atoi((char*)argv[i]); 
    } 
    float average = (float)sum / (float)(count-1); 
    printf("Sum = %i\nAverage = %.3f\n",sum, average); 
    return 0; 
}



// int main(void)
// {
//     int a[] = {3, 7, 1, 9, 5};

//     int max = a[0];  // Assume first is the largest
//     for (int i = 1; i < 5; i++) {
//         if (a[i] > max) {
//             max = a[i];
// }
//     }

//    printf("Max number is: %d\n", max);
//     return 0;
// }

// int main(void)
// {
//     int v[] = {1, 2, 3, 4, 5};
//     int reverse[5];

//     for(int i = 4; i >= 0; i--){
//         reverse[4 - i] = v[i];
//     }
//     printf("reversed: ");

//     for(int i = 0; i < 5; i++) {
//         printf("%d ", reverse[i]);
//     }
//     printf("\n");

//     return 0;
// }



// int main(void)
// {
//     int a[] = {3, 7, 1, 9, 5};
//     int n = sizeof(a) / sizeof(a[0]);
//     int max = a[0];

//     for(int i = 0; i < n; i++){
//         if(a[i] > max) {
//             max = a[i];
//         }
//     }

//     printf("The maximum number in the array is: %d\n", max);
//     return 0;

// } 


// int main(void){

//     char name[] = "EMEKA NWOSU";
//     int count = 0;

//     // Count characters until the null terminator
//     while (name[count] != '\0') {
//         count++;
//     }

//     printf("The number of characters in the array is: %d\n", count);

//     return 0;
// }



// int main() {
//     char name[] = "EMEKA NWOSU";
//     int count = 0;

//     do {
//         if (name[count] == '\0')
//             break;
//         count++;
//     } while (1);

//     printf("The number of characters in the array is: %d\n", count);

//     return 0;
// }

// int main(int argc, char* argv[]){

//     char name[] = "EMEKA NWOSU";

   
//     for(int i = 0; i < argc; i++){

//         printf("%c \n", argv[i][0]);

//     }

    

//     return 0;
// }

// void getInitials(int argc, char* argv[]);

// int main(int argc, char* argv[]){
//     printf("Initials: ");
//     getInitials(argc, argv);
//     printf("\n");
//     return 0;
// } 

// void getInitials(int argc, char* argv[]) {
//     for (int i = 1; i < argc; i++) {
//         if (argv[i][0] != '\0') { 
//             printf("%c.",  argv[i][0]);
//         }
//     }
// }

