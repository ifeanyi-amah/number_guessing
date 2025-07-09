#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_CONTACTS 50

typedef struct {
    char name[MAX_LEN];
    char phone[MAX_LEN];
    char email[MAX_LEN];
} Contact;

Contact contacts[MAX_CONTACTS];
int contact_count = 0;


// Add contact
void add_contact(const char *name, const char *phone, const char *email) {
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }

    strncpy(contacts[contact_count].name, name, MAX_LEN);
    strncpy(contacts[contact_count].phone, phone, MAX_LEN);
    strncpy(contacts[contact_count].email, email, MAX_LEN);
    contact_count++;

    printf("Added contact: %s\n", name);
}

// Remove contact by name
void remove_contact(const char *name) {
    int found = 0;
    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            found = 1;
            // Shift remaining contacts up
            for (int j = i; j < contact_count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contact_count--;
            printf("Removed contact: %s\n", name);
            break;
        }
    }
    if (!found) {
        printf("Contact not found: %s\n", name);
    }
}

// Print all contacts
void list_contacts() {
    printf("All Contacts:\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%d. %s | %s | %s\n", i + 1,
               contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

// Search contact by name
void search_contact(const char *name) {
    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found contact:\n");
            printf("  Name : %s\n", contacts[i].name);
            printf("  Phone: %s\n", contacts[i].phone);
            printf("  Email: %s\n", contacts[i].email);
            return;
        }
    }
    printf("Contact not found: %s\n", name);
}

int main(int argc, char *argv[]) {

     if (argc < 2) {
        printf("Usage:\n");
        printf("  --add name phone email\n");
        printf("  --remove name\n");
        printf("  --search name\n");
        printf("  --list\n");

        return 1;
    }

    if (strcmp(argv[1], "--add") == 0 && argc == 5) {
        add_contact(argv[2], argv[3], argv[4]);
    } 


    printf("Argument count: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Arg %d: %s\n", i, argv[i]);
    }
    return 0;
}
