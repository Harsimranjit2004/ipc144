/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Harsimranjit singh
Student ID#: 155452220
Email      : hsingh956@myseneca.ca
Section    : NNN

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
//#include "core.c"
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient *patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ",
               patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do
    {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient *patient)
{
    int selection;

    do
    {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ",
               patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}

// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;
    int flag = 0;
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {

            displayPatientData(&patient[i], fmt);
        }
        flag = 1;
    }
    if (flag == 0)
    {
        printf("*** No records found ***");
    }
    printf("\n");
}
// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
    int selection;
    do
    {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d", &selection);
        printf("\n");
        if (selection == 1)
        {
            searchPatientByPatientNumber(patient, max);
	printf("\n");
            suspend();

        
        }
        else if (selection == 2)
        {
            searchPatientByPhoneNumber(patient, max);
		printf("\n");
            suspend();

        
        }

    } while (selection != 0);

}

// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{

    int i;
    int index = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > 0)
        {

            index++;
        }
    }

    if (index < max)
    {
        int patientNumber = nextPatientNumber(patient, max);
        printf("Patient Data Input\n");
        printf("------------------\n");
        printf("Number: %05d\n", patientNumber);
        patient[index].patientNumber = patientNumber;
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n\n");
    }
    else
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}

// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{
    int patient_number;
    int patient_index;
    printf("Enter the patient number: ");
    scanf("%d", &patient_number);
    patient_index = findPatientIndexByPatientNum(patient_number, patient, max);
    printf("\n");
    if (patient_index >= 0 && patient_index < max)
    {

        menuPatientEdit(&patient[patient_index]);
    }
    else
    {
        printf("ERROR: Patient record not found!\n");
    }
}

// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
    int patient_number;
    int patient_index;
    printf("Enter the patient number: ");
    scanf("%d", &patient_number);

    patient_index = findPatientIndexByPatientNum(patient_number, patient, max);

    if (patient_index >= 0 && patient_index < max)
    {

        char option;

        clearInputBuffer();
        printf("\n");
        displayPatientData(&patient[patient_index], 1);
        printf("\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &option);
        if (option == 'y' || option == 'Y')
        {
            patient[patient_index] = (struct Patient){0};
            printf("Patient record has been removed!\n\n");
        }
        else
        {

            printf("Operation aborted.\n\n");
        }
    }
    else
    {
        printf("\n");
        printf("ERROR: Patient record not found!\n\n");
    }
    clearInputBuffer();
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patient_number;
    int patient_index;
    printf("Search by patient number: ");
    scanf("%d", &patient_number);
    printf("\n");

    patient_index = findPatientIndexByPatientNum(patient_number, patient, max);

    if (patient_index >= 0 && patient_index < max)
    {
        displayPatientData(&patient[patient_index], 1);
        
    }
    else
    {
	
        printf("*** No records found ***\n");
    }
    clearInputBuffer();
}

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    char phone_number[PHONE_LEN + 1];
    int i;
    int recordfound = 0;
    printf("Search by phone number: ");
    scanf("%s", phone_number);
    printf("\n");
    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        if (strcmp(patient[i].phone.number, phone_number) == 0)
        {

            displayPatientData(&patient[i], 2);
            recordfound = 1;
        }
    }

    if (recordfound == 0)
    {
	printf("\n");
        printf("*** No records found ***\n");
    }
    clearInputBuffer();
}
// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{
    int max_id = 0;
    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > max_id)
        {
            max_id = patient[i].patientNumber;
        }
    }
    return max_id + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int index = -1;
    int i;
    for (i = 0; i < max; i++)
        if (patient[i].patientNumber == patientNumber)
        {
            return i;
        }

    return index;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient *patient)
{

    printf("Name  : ");
    scanf("%[^\n]s", patient->name);
    printf("\n");
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
void inputPhoneData(struct Phone *phone)
{
    int option;
    
    printf("Phone Information\n");
    printf("-----------------\n");

    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n2. Home\n3. Work\n4. TBD\n");
    printf("Selection: ");
    scanf("%d", &option);

    if (option == 4)
    {
        *phone->number = '\0';

        strcpy(phone->description, "TBD");
    }
    else
    {
        printf("\n");
        if (option == 3)
        {

            printf("Contact: WORK\n");
            strcpy(phone->description, "WORK");
        }
        else if (option == 2)
        {
            printf("Contact: HOME\n");
            strcpy(phone->description, "HOME");
        }
        else if (option == 1)
        {
            printf("Contact: CELL\n");
            strcpy(phone->description, "CELL");
        }
        printf("Number : ");
        scanf("%s", phone->number);
    }
    printf("\n");
    clearInputBuffer();
}