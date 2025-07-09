// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int main(int argc, char* argv[]){

//     int number[3];

//     printf("Hello, %s \n", argv[1]);

// }



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int *Numbers;

// #define MAX_TRAINEES 100

#define MAX_NAME_LENGTH 50
#define MAX_REG_LENGTH 10
#define MAX_CLASS_NAME_LENGTH 15    

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char reg[MAX_REG_LENGTH];
    char class_name[MAX_CLASS_NAME_LENGTH];
} Trainee;



int main(int argc, char **argv)
{
    // argv[0] is the program name, so we check if at least one argument is provided
    if (argc < 4)
    {
        fprintf(stderr, "Provide at least 4 argv's. Usage: %s <name> <reg> <class_name>\n", argv[0]);
        return 1;
    }
    Trainee registered_trainee;

    // int num = sizeof(registered_trainee);
    int num = 6;

    strncpy(registered_trainee.name, argv[1], MAX_NAME_LENGTH - 1);
    strncpy(registered_trainee.reg, argv[2], MAX_REG_LENGTH - 1);
    strncpy(registered_trainee.class_name, argv[3], MAX_CLASS_NAME_LENGTH - 1);

     // Fill the arrays
    for (int i = 0; i < num; i++) {
       printf("| %s | %s | %s |\n", registered_trainee.name, registered_trainee.reg, registered_trainee.class_name ); 
    }
   


    return 0;
}