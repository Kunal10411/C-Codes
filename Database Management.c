#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

struct Record {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

struct Database {
    struct Record records[MAX_RECORDS];
    int numRecords;
};

void initializeDatabase(struct Database *db) {
    db->numRecords = 0;
}

void addRecord(struct Database *db, const char *name, const char *email) {
    if (db->numRecords < MAX_RECORDS) {
        strcpy(db->records[db->numRecords].name, name);
        strcpy(db->records[db->numRecords].email, email);
        db->numRecords++;
        printf("Record added successfully.\n");
    } else {
        printf("Database is full. Cannot add more records.\n");
    }
}

void deleteRecord(struct Database *db, const char *name) {
    int i, found = 0;
    for (i = 0; i < db->numRecords; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            found = 1;
            // Move records after the deleted record to fill the gap
            for (int j = i; j < db->numRecords - 1; j++) {
                strcpy(db->records[j].name, db->records[j + 1].name);
                strcpy(db->records[j].email, db->records[j + 1].email);
            }
            db->numRecords--;
            printf("Record deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
    }
}

void searchRecord(const struct Database *db, const char *name) {
    int i, found = 0;
    for (i = 0; i < db->numRecords; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            found = 1;
            printf("Record found:\n");
            printf("Name: %s\n", db->records[i].name);
            printf("Email: %s\n", db->records[i].email);
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
    }
}

void displayMenu() {
    printf("\nDatabase Management System\n");
    printf("1. Add Record\n");
    printf("2. Delete Record\n");
    printf("3. Search Record\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Database myDatabase;
    initializeDatabase(&myDatabase);

    int choice;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addRecord(&myDatabase, name, email);
                break;
            case 2:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteRecord(&myDatabase, name);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchRecord(&myDatabase, name);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
