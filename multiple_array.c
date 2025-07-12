
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

#include <stdio.h>
#include <string.h>
// #include "include/input_utils.h"

#define MAX_CONTACTS 10
typedef struct
{
    char name[50];
    char phone[10];
} Contact;

int main (void)


{
        Contact contacts[5] = {
        { "Alice Johnson",   "555-1234" },
        { "Bob Smith",       "555-2345" },
        { "Carol Martinez",  "555-3456" },
        { "Dave Thompson",   "555-4567" },
        { "Eve Nguyen",      "555-5678" }
    };

    int contact_count = 6;

    // Print each contact
    for (int i = 0; i < 6; i++) {
        printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
    }

     // Ask user how many new contacts to add
    int add_count = 0;
    printf("\nHow many new contacts would you like to add? ");
    scanf("%d", &add_count);
    getchar(); // Clear newline left in input buffer

    if (contact_count + add_count > MAX_CONTACTS) {
        printf("Sorry, you can only add up to %d more contacts.\n", MAX_CONTACTS - contact_count);
        add_count = MAX_CONTACTS - contact_count;
    }

    

    // Add new contacts
    // for (int i = 0; i < add_count; i++) {
    //     printf("\nEnter name for contact %d: ", contact_count + 1);
    //     get_string(contacts[contact_count].name, sizeof(contacts[contact_count].name));

    //     printf("Enter phone for contact %d: ", contact_count + 1);
    //     get_string(contacts[contact_count].phone, sizeof(contacts[contact_count].phone));

    //     contact_count++;
    // }

    // Final contact list
    // printf("\nUpdated Contact List:\n");
    // for (int i = 0; i < contact_count; i++) {
    //     printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
    // }

 return 0;
}