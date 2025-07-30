#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_PHONE 20
#define MAX_EMAIL 100
#define CONTACTS_FILE "contacts.csv"

typedef struct {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
} Contact;

Contact *contacts = NULL;
int contactCount = 0;

// Function Prototypes
void loadContacts();
void saveContacts();
void addContact();
void viewContacts();
void updateContact();
void deleteContact();
void freeMemory();

int main() {
    loadContacts();
    int choice;

    do {
        printf("\nCONTACTS MANAGER\n");
        printf("1. View Contacts\n");
        printf("2. Add Contact\n");
        printf("3. Update Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1: viewContacts(); break;
            case 2: addContact(); break;
            case 3: updateContact(); break;
            case 4: deleteContact(); break;
            case 5: saveContacts(); break;
            default: printf("Invalid option.\n");
        }

    } while (choice != 5);

    freeMemory();
    return 0;
}

void loadContacts() {
    FILE *file = fopen(CONTACTS_FILE, "r");
    if (!file) return;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        contacts = realloc(contacts, (contactCount + 1) * sizeof(Contact));
        sscanf(line, "%99[^,],%19[^,],%99[^\n]",
               contacts[contactCount].name,
               contacts[contactCount].phone,
               contacts[contactCount].email);
        contactCount++;
    }
    fclose(file);
}

void saveContacts() {
    FILE *file = fopen(CONTACTS_FILE, "w");
    if (!file) {
        printf("Failed to save contacts.\n");
        return;
    }

    for (int i = 0; i < contactCount; i++) {
        fprintf(file, "%s,%s,%s\n",
                contacts[i].name,
                contacts[i].phone,
                contacts[i].email);
    }

    fclose(file);
    printf("Contacts saved.\n");
}

void viewContacts() {
    if (contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\n%-4s %-20s %-15s %-30s\n", "ID", "Name", "Phone", "Email");
    for (int i = 0; i < contactCount; i++) {
        printf("%-4d %-20s %-15s %-30s\n", i + 1,
               contacts[i].name,
               contacts[i].phone,
               contacts[i].email);
    }
}

void addContact() {
    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, MAX_NAME, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0;

    printf("Enter phone: ");
    fgets(newContact.phone, MAX_PHONE, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0;

    printf("Enter email: ");
    fgets(newContact.email, MAX_EMAIL, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = 0;

    Contact *temp = realloc(contacts, (contactCount + 1) * sizeof(Contact));
    if (!temp) {
        printf("Memory allocation failed.\n");
        return;
    }
    contacts = temp;
    contacts[contactCount++] = newContact;
    printf("Contact added.\n");
}

void updateContact() {
    viewContacts();
    int index;
    printf("Enter contact ID to update: ");
    scanf("%d", &index);
    getchar(); // clear newline

    if (index < 1 || index > contactCount) {
        printf("Invalid ID.\n");
        return;
    }
    index--; // Adjust for 0-based index

    printf("Enter new name (%s): ", contacts[index].name);
    fgets(contacts[index].name, MAX_NAME, stdin);
    contacts[index].name[strcspn(contacts[index].name, "\n")] = 0;

    printf("Enter new phone (%s): ", contacts[index].phone);
    fgets(contacts[index].phone, MAX_PHONE, stdin);
    contacts[index].phone[strcspn(contacts[index].phone, "\n")] = 0;

    printf("Enter new email (%s): ", contacts[index].email);
    fgets(contacts[index].email, MAX_EMAIL, stdin);
    contacts[index].email[strcspn(contacts[index].email, "\n")] = 0;

    printf("Contact updated.\n");
}

void deleteContact() {
    viewContacts();
    int index;
    printf("Enter contact ID to delete: ");
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > contactCount) {
        printf("Invalid ID.\n");
        return;
    }
    index--;

    for (int i = index; i < contactCount - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    contactCount--;

    Contact *temp = realloc(contacts, contactCount * sizeof(Contact));
    if (temp || contactCount == 0) {
        contacts = temp;
    }

    printf("Contact deleted.\n");
}

void freeMemory() {
    free(contacts);
}