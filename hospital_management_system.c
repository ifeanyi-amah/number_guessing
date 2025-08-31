#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 64
#define MAX_DATE_LEN 16
#define MAX_DESC_LEN 128
#define MAX_PATIENTS 100
#define MAX_APPOINTMENTS 200
#define MAX_TREATMENTS 200

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int age;
    char sex[8];
    char phone[24];
    int is_active;
} Patient;

typedef struct {
    int id;
    int patient_id;
    char date[MAX_DATE_LEN];
    char time[8];
    char doctor[MAX_NAME_LEN];
    int is_active;
} Appointment;

typedef struct {
    int id;
    int patient_id;
    char date[MAX_DATE_LEN];
    char description[MAX_DESC_LEN];
    int is_active;
} Treatment;

// Global arrays
Patient patients[MAX_PATIENTS];
Appointment appointments[MAX_APPOINTMENTS];
Treatment treatments[MAX_TREATMENTS];
int patient_count = 0, appointment_count = 0, treatment_count = 0;

// ===== LOAD & SAVE PATIENTS =====
void loadPatients() {
    FILE *fp = fopen("patients.csv", "r");
    if (!fp) return;
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        Patient p;
        char *token = strtok(line, ",");
        p.id = atoi(token);
        token = strtok(NULL, ","); strcpy(p.name, token);
        token = strtok(NULL, ","); p.age = atoi(token);
        token = strtok(NULL, ","); strcpy(p.sex, token);
        token = strtok(NULL, ","); strcpy(p.phone, token);
        token = strtok(NULL, ","); p.is_active = atoi(token);
        p.phone[strcspn(p.phone, "\n")] = '\0';
        patients[patient_count++] = p;
    }
    fclose(fp);
}

void savePatients() {
    FILE *fp = fopen("patients.csv", "w");
    for (int i = 0; i < patient_count; i++) {
        fprintf(fp, "%d,%s,%d,%s,%s,%d\n",
                patients[i].id, patients[i].name, patients[i].age,
                patients[i].sex, patients[i].phone, patients[i].is_active);
    }
    fclose(fp);
}

// ===== LOAD & SAVE APPOINTMENTS =====
void loadAppointments() {
    FILE *fp = fopen("appointments.csv", "r");
    if (!fp) return;
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        Appointment a;
        char *token = strtok(line, ",");
        a.id = atoi(token);
        token = strtok(NULL, ","); a.patient_id = atoi(token);
        token = strtok(NULL, ","); strcpy(a.date, token);
        token = strtok(NULL, ","); strcpy(a.time, token);
        token = strtok(NULL, ","); strcpy(a.doctor, token);
        token = strtok(NULL, ","); a.is_active = atoi(token);
        a.doctor[strcspn(a.doctor, "\n")] = '\0';
        appointments[appointment_count++] = a;
    }
    fclose(fp);
}

void saveAppointments() {
    FILE *fp = fopen("appointments.csv", "w");
    for (int i = 0; i < appointment_count; i++) {
        fprintf(fp, "%d,%d,%s,%s,%s,%d\n",
                appointments[i].id, appointments[i].patient_id,
                appointments[i].date, appointments[i].time,
                appointments[i].doctor, appointments[i].is_active);
    }
    fclose(fp);
}

// ===== LOAD & SAVE TREATMENTS =====
void loadTreatments() {
    FILE *fp = fopen("treatments.csv", "r");
    if (!fp) return;
    char line[300];
    while (fgets(line, sizeof(line), fp)) {
        Treatment t;
        char *token = strtok(line, ",");
        t.id = atoi(token);
        token = strtok(NULL, ","); t.patient_id = atoi(token);
        token = strtok(NULL, ","); strcpy(t.date, token);
        token = strtok(NULL, ","); strcpy(t.description, token);
        token = strtok(NULL, ","); t.is_active = atoi(token);
        t.description[strcspn(t.description, "\n")] = '\0';
        treatments[treatment_count++] = t;
    }
    fclose(fp);
}

void saveTreatments() {
    FILE *fp = fopen("treatments.csv", "w");
    for (int i = 0; i < treatment_count; i++) {
        fprintf(fp, "%d,%d,%s,%s,%d\n",
                treatments[i].id, treatments[i].patient_id,
                treatments[i].date, treatments[i].description,
                treatments[i].is_active);
    }
    fclose(fp);
}

// ====== CRUD FUNCTIONS ======
void addPatient() {
    if (patient_count >= MAX_PATIENTS) return;
    Patient p;
    p.id = patient_count + 1;
    printf("Enter name: "); fgets(p.name, MAX_NAME_LEN, stdin);
    p.name[strcspn(p.name, "\n")] = '\0';
    printf("Enter age: "); scanf("%d", &p.age); getchar();
    printf("Enter sex: "); fgets(p.sex, sizeof(p.sex), stdin);
    p.sex[strcspn(p.sex, "\n")] = '\0';
    printf("Enter phone: "); fgets(p.phone, sizeof(p.phone), stdin);
    p.phone[strcspn(p.phone, "\n")] = '\0';
    p.is_active = 1;
    patients[patient_count++] = p;
    printf("Patient added!\n");
}

void listPatients() {
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].is_active) {
            printf("%d: %s | Age %d | %s | %s\n",
                   patients[i].id, patients[i].name,
                   patients[i].age, patients[i].sex, patients[i].phone);
        }
    }
}

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) return;
    Appointment a;
    a.id = appointment_count + 1;
    printf("Enter patient ID: "); scanf("%d", &a.patient_id); getchar();
    printf("Enter date (YYYY-MM-DD): "); fgets(a.date, MAX_DATE_LEN, stdin);
    a.date[strcspn(a.date, "\n")] = '\0';
    printf("Enter time (HH:MM): "); fgets(a.time, sizeof(a.time), stdin);
    a.time[strcspn(a.time, "\n")] = '\0';
    printf("Enter doctor: "); fgets(a.doctor, sizeof(a.doctor), stdin);
    a.doctor[strcspn(a.doctor, "\n")] = '\0';
    a.is_active = 1;
    appointments[appointment_count++] = a;
    printf("Appointment added!\n");
}

void listAppointments() {
    for (int i = 0; i < appointment_count; i++) {
        if (appointments[i].is_active) {
            printf("%d: Patient %d | %s %s | Dr. %s\n",
                   appointments[i].id, appointments[i].patient_id,
                   appointments[i].date, appointments[i].time, appointments[i].doctor);
        }
    }
}

void addTreatment() {
    if (treatment_count >= MAX_TREATMENTS) return;
    Treatment t;
    t.id = treatment_count + 1;
    printf("Enter patient ID: "); scanf("%d", &t.patient_id); getchar();
    printf("Enter date (YYYY-MM-DD): "); fgets(t.date, MAX_DATE_LEN, stdin);
    t.date[strcspn(t.date, "\n")] = '\0';
    printf("Enter description: "); fgets(t.description, MAX_DESC_LEN, stdin);
    t.description[strcspn(t.description, "\n")] = '\0';
    t.is_active = 1;
    treatments[treatment_count++] = t;
    printf("Treatment added!\n");
}

void listTreatments() {
    for (int i = 0; i < treatment_count; i++) {
        if (treatments[i].is_active) {
            printf("%d: Patient %d | %s | %s\n",
                   treatments[i].id, treatments[i].patient_id,
                   treatments[i].date, treatments[i].description);
        }
    }
}

// ===== MENU =====
void menu() {
    int choice;
    do {
        printf("\n--- Hospital Management System ---\n");
        printf("1. Add Patient\n2. List Patients\n");
        printf("3. Add Appointment\n4. List Appointments\n");
        printf("5. Add Treatment\n6. List Treatments\n");
        printf("0. Save & Exit\nChoice: ");
        scanf("%d", &choice); getchar();
        switch (choice) {
            case 1: addPatient(); break;
            case 2: listPatients(); break;
            case 3: addAppointment(); break;
            case 4: listAppointments(); break;
            case 5: addTreatment(); break;
            case 6: listTreatments(); break;
            case 0:
                savePatients();
                saveAppointments();
                saveTreatments();
                printf("Data saved. Goodbye!\n");
                break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);
}

int main() {
    loadPatients();
    loadAppointments();
    loadTreatments();
    menu();
    return 0;
}