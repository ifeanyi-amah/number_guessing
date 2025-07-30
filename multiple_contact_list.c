#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #define MAX_CONTACTS 100

typedef struct
{
    char name[50];
    char phone[10];
} Contact;
void print_array(Contact *contact_list, int n); 
void add_contact(Contact *contact_list, int *contactnum); 
void delete_contact(Contact *contact_list, int *contactnum); 
// int delete_contact(Contact *contact_list, int *n, const char *name_to_delete);
// void deleteContact(Contact contacts[], int *count, const char *nameToDelete);

int main(void)
{
    Contact contacts[8] = {
        {"Alice Johnson", "555-1234"},
        {"Bob Smith", "555-2345"},
        {"Carol Martinez", "555-3456"},
        {"Dave Thompson", "555-4567"},
        {"Eve Nguyen", "555-5678"}
    };


    int contactnum = sizeof(contacts) / sizeof(Contact);
    



    int choice;
    do
    {
        printf("\n--- Contact Manager ---\n");
        printf("1. View Contacts\n");
        printf("2. Add Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer
        

        switch(choice)
        {
            case 1:
                printf("Number of contacts is %i\n", contactnum);
                print_array(contacts, contactnum);
                break;
            case 2:
                add_contact(contacts, &contactnum);
                break;
            case 3:
                // delete_contact(contacts, &contactnum);
                break;
            case 4:
                printf("Thank for your time, you are exiting now... \n");
                break;
            default:
                printf("Invalid option. Please Try again. \n");
                break;                
        }

    } while (choice != 4);

    return 0;

    


    
    
}

void print_array(Contact *contact_list, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d. %s %s\n",i + 1, contact_list[i].name, contact_list[i].phone);
    }
}

void add_contact(Contact *contacts, int *contactnum){

        if (*contactnum >= 8){
            printf("Contact List is full! \n");
            // return;
        }

        printf("Enter new contact name: ");
        
        fgets(contacts[5].name,50,stdin);
        contacts[5].name[strcspn(contacts[5].name,"\n")]='\0';

        printf("Enter new contact phone: ");
        fgets(contacts[5].phone,10,stdin);
        contacts[5].phone[strcspn(contacts[5].phone,"\n")]='\0';

        (contactnum)++;
        printf("Contact added successfully.\n");
        // print_array(contacts,contactnum);


    }





// Extend this code to Add and delete new contact to the list, from user input





// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// typedef struct
// {
//     char name[50];
//     char phone[10];
// } Contact;

// void print_array(Contact *contact_list, int n); 
// int delete_contact(Contact *contact_list, int *n, const char *name_to_delete);

// int main(void)
// {
//     Contact contacts[6] = {
//         {"Alice Johnson", "555-1234"},
//         {"Bob Smith", "555-2345"},
//         {"Carol Martinez", "555-3456"},
//         {"Dave Thompson", "555-4567"},
//         {"Eve Nguyen", "555-5678"}
//     };

//     int contactnum = 5; // Only 5 contacts initialized
//     printf("Number of contacts is %i\n", contactnum);
//     print_array(contacts, contactnum);

//     // Add new contact
//     printf("\nEnter new contact name: ");
//     fgets(contacts[contactnum].name, 50, stdin);
//     contacts[contactnum].name[strcspn(contacts[contactnum].name, "\n")] = '\0';

//     printf("Enter new contact phone: ");
//     fgets(contacts[contactnum].phone, 10, stdin);
//     contacts[contactnum].phone[strcspn(contacts[contactnum].phone, "\n")] = '\0';

//     contactnum++;

//     printf("\nUpdated contact list:\n");
//     print_array(contacts, contactnum);

//     // Delete contact
//     char name_to_delete[50];
//     printf("\nEnter contact name to delete: ");
//     fgets(name_to_delete, 50, stdin);
//     name_to_delete[strcspn(name_to_delete, "\n")] = '\0';

//     if (delete_contact(contacts, &contactnum, name_to_delete))
//     {
//         printf("Contact deleted successfully.\n");
//     }
//     else
//     {
//         printf("Contact not found.\n");
//     }

//     printf("\nFinal contact list:\n");
//     print_array(contacts, contactnum);

//     return 0;
// }

// void print_array(Contact *contact_list, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%s %s\n", contact_list[i].name, contact_list[i].phone);
//     }
// }

// int delete_contact(Contact *contact_list, int *n, const char *name_to_delete)
// {
//     for (int i = 0; i < *n; i++)
//     {
//         if (strcmp(contact_list[i].name, name_to_delete) == 0)
//         {
//             // Shift remaining contacts
//             for (int j = i; j < *n - 1; j++)
//             {
//                 contact_list[j] = contact_list[j + 1];
//             }
//             (*n)--;
//             return 1; // Success
//         }
//     }
//     return 0; // Not found
// }



