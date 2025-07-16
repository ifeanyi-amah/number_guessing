#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACTS 100

typedef struct
{
    char name[50];
    char phone[15];
} Contact;

void print_array(Contact *contact_list, int n);
void add_contact(Contact *contacts, int *contactnum);
void delete_contact(Contact *contacts, int *contactnum);

int main(void)
{
    Contact contacts[MAX_CONTACTS] = {
        {"Alice Johnson", "555-1234"},
        {"Bob Smith", "555-2345"},
        {"Carol Martinez", "555-3456"},
        {"Dave Thompson", "555-4567"},
        {"Eve Nguyen", "555-5678"}
    };

    int contactnum = 5; // Initially 5 contacts

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

        switch (choice)
        {
            case 1:
                print_array(contacts, contactnum);
                break;
            case 2:
                add_contact(contacts, &contactnum);
                break;
            case 3:
                delete_contact(contacts, &contactnum);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}

void print_array(Contact *contact_list, int n)
{
    if (n == 0)
    {
        printf("Contact list is empty.\n");
        return;
    }

    printf("\nContact List:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d. %s - %s\n", i + 1, contact_list[i].name, contact_list[i].phone);
    }
}

void add_contact(Contact *contacts, int *contactnum)
{
    if (*contactnum >= MAX_CONTACTS)
    {
        printf("Contact list is full!\n");
        return;
    }

    printf("Enter new contact name: ");
    fgets(contacts[*contactnum].name, 50, stdin);
    contacts[*contactnum].name[strcspn(contacts[*contactnum].name, "\n")] = '\0';

    printf("Enter new contact phone: ");
    fgets(contacts[*contactnum].phone, 15, stdin);
    contacts[*contactnum].phone[strcspn(contacts[*contactnum].phone, "\n")] = '\0';

    (*contactnum)++;
    printf("Contact added successfully.\n");
}

void delete_contact(Contact *contacts, int *contactnum)
{
    if (*contactnum == 0)
    {
        printf("No contacts to delete.\n");
        return;
    }

    int index;
    print_array(contacts, *contactnum);
    printf("Enter the contact number to delete (1-%d): ", *contactnum);
    scanf("%d", &index);
    getchar(); // Clear newline

    if (index < 1 || index > *contactnum)
    {
        printf("Invalid contact number.\n");
        return;
    }

    for (int i = index - 1; i < *contactnum - 1; i++)
    {
        contacts[i] = contacts[i + 1];
    }

    (*contactnum)--;
    printf("Contact deleted successfully.\n");
}










