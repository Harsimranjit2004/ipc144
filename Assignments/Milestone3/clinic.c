/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
// #include "core.c"
//#include "a1ms3.c"
#include "core.h"
//#include "core.c"
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

void displayScheduleTableHeader(const struct Date *date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient *patient,
                         const struct Appointment *appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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

void menuAppointment(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
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

    int  index, locate;
    int i = 0;

    do
    {
        locate = 0;
        if (patient[i].patientNumber == 0)
        {
            locate = 1;
            index = i;
        }
        i++;
    } while (i < max && locate == 0);
    if (locate == 0)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        int patientNumber = nextPatientNumber(patient, max);
        printf("Patient Data Input\n");
        printf("------------------\n");
        printf("Number: %05d\n", patientNumber);
        patient[index].patientNumber = patientNumber;
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n\n");
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
        printf("\n");
        displayPatientData(&patient[patient_index], 1);
        printf("\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");

        option = inputCharOption("yn");
        // scanf(" %c",&option);

        if (option == 'y' || option == 'Y')
        {

            patient[patient_index].patientNumber = 0;
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
        clearInputBuffer();
    }
}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(struct ClinicData *data)
{
    int i, j;
    struct Date temp_date;
    int AppointmentLen = 0;
    sort(data->appointments,data->maxAppointments);
    while (data->appointments[AppointmentLen].patientNumber != 0)
    {
        AppointmentLen++;
    }
    int patientLen = 0;
    while (data->patients[patientLen].patientNumber != 0)
    {
        patientLen++;
    }

    displayScheduleTableHeader(&temp_date, ALL_DATA);

    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
            {
                displayScheduleData(&data->patients[j], &data->appointments[i], 1);
            }
        }
    }
   
    printf("\n");
}

void viewAppointmentSchedule(struct ClinicData *data)
{
    int lastDay = 31;
    int i, j;
    struct Date date;

    // Taking the year as input
    printf("Year        : ");
    date.year = inputIntPositive();

    // Taking the month as input
    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);

    // Taking the day as input
    printf("Day (1-");
    lastDay = monthUpperLimit(date.year,date.month);
    printf("%d)  : ", lastDay);
    date.day = inputIntRange(1, lastDay);
    printf("\n");

    // Sorting the data is the array
    sort(data->appointments, data->maxAppointments);

    // Displaying the patients
    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++) {
        for (j = 0; j < data->maxPatient; j++) {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber) {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) {
                    if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day) {
                        displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    }
                }
            }
        }
    }

    printf("\n");

  
}


void addAppointment(struct Appointment* app, int maxAppointments, struct Patient* pt, int maxPatients) {

    struct Date date;
    struct Time time;
    int upperLimit;
    int patientNumber, index, slotNotAvailable = 1;

  
    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNumber, pt, maxPatients);

    if (index >= 0) {
        while (slotNotAvailable)
        {
            printf("Year        : ");
            date.year = inputIntPositive();
            printf("Month (1-12): ");
            date.month = inputIntRange(1, 12);
            printf("Day (1-");
           
            upperLimit = monthUpperLimit(date.year,date.month);

            printf("%d)  : ", upperLimit);
            date.day = inputIntRange(1, upperLimit);

            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);

            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);

            // Checking whether time slot is available
            if (timeSlotAvailable(date, time, app, maxAppointments)) {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }
            else {
                while ((time.hour < START_TIME || time.hour > END_TIME) || (time.hour == END_TIME && time.min > 0) || (time.min % MINUTE_INTERVAL != 0)) {
                    printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START_TIME, END_TIME, MINUTE_INTERVAL);
                    printf("Hour (0-23)  : ");
                    time.hour = inputIntRange(0, 23);
                    printf("Minute (0-59): ");
                    time.min = inputIntRange(0, 59);
                }
                slotNotAvailable = 0;
            }
        }

      
        index = nextSlot(app, maxAppointments);
        app[index].date = date;
        app[index].time = time;
        app[index].patientNumber = patientNumber;
        printf("\n*** Appointment scheduled! ***\n\n");
    }
    else {
        printf("\nERROR: Patient record not found!\n\n");
    }
    return;
}


    void removeAppointment(struct Appointment appointments[], int maxAppointments, struct Patient patients[], int maxPatients)
    {
   
        int patientNumber;
        int i;
        int found = 0;
        struct Date temp_date;
        int patientIndex;
        char option;
        printf("Patient Number: ");
        patientNumber = inputIntPositive();
        for (i = 0; i < maxAppointments; i++)
        {
            if (appointments[i].patientNumber == patientNumber)
            {

                found = 1;
            }
        }
        if (found == 0)
        {
            printf("ERROR: Patient record not found!\n");
            printf("\n");
        }
        if (found == 1)
        {
            printf("Year        : ");
            scanf("%d", &temp_date.year);
            printf("Month (1-12): ");
            temp_date.month = inputIntRange(1, 12);
            int upperLimit;
            upperLimit = monthUpperLimit(temp_date.year, temp_date.month);
            printf("Day (1-%d)  : ", upperLimit);
            temp_date.day = inputIntRange(1, upperLimit);
            printf("\n");

            patientIndex = findPatientIndexByPatientNum(patientNumber, patients, maxPatients);
            displayPatientData(&patients[patientIndex], 1);
            
            printf("Are you sure you want to remove this appointment (y,n): ");
            
            // scanf(" %c", &option);
            option = inputCharOption("yn");
            printf("\n");
            if (option == 'y')
            {
                for (i = 0; i < maxAppointments; i++)
                {
                    if (appointments[i].patientNumber == patientNumber && appointments[i].date.day == temp_date.day && appointments[i].date.month == temp_date.month && appointments[i].date.day == temp_date.day)
                    {
                        appointments[i].patientNumber = 0;
                    }
                }
                printf("Appointment record has been removed!\n\n");
            }
        }
        
    }

    // Remove an appointment record from the appointment array
    // Todo:

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
    void sort(struct Appointment appoints[], int max) {
    int i, j;
    struct Appointment temp;

    // Storing all the date and time values in minutes for comparison
    for (i = 0; i < max; i++) {
        appoints[i].time.min = (appoints[i].date.year * 12 * 30 * 24 * 60) + (appoints[i].date.month * 30 * 24 * 60) + (appoints[i].date.day * 24 * 60) + (appoints[i].time.hour * 60) + appoints[i].time.min;
    }

    // Using bubble sort to compare minutes and then swap the structs
    for (i = max - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (appoints[j].time.min > appoints[j + 1].time.min)
            {
                temp = appoints[j];
                appoints[j] = appoints[j + 1];
                appoints[j + 1] = temp;
            }
        }
    }

    // Converting total minutes back to minutes
    for (i = 0; i < max; i++) {
        appoints[i].time.min = appoints[i].time.min - (appoints[i].date.year * 12 * 30 * 24 * 60) - (appoints[i].date.month * 30 * 24 * 60) - (appoints[i].date.day * 24 * 60) - (appoints[i].time.hour * 60);
    }

}
    
    int monthUpperLimit(int year, int month)
    {
        if (month == 1)
            return 31;
        if (month == 2)
        {
            if (year % 4 == 0)
            {
                return 29;
            }
            else
            {
                return 28;
            }
        }
        if (month == 3)
            return 31;
        if (month == 4)
            return 30;
        if (month == 5)
            return 31;
        if (month == 6)
            return 30;
        if (month == 7)
            return 31;
        if (month == 8)
            return 31;
        if (month == 9)
            return 30;
        if (month == 10)
            return 31;
        if (month == 11)
            return 30;
        if (month == 12)
            return 31;
        return 0;
    }
int nextSlot(struct Appointment* app, int maxAppointments) {
    int i = 0, found= 0;
    while (found == 0 && i < maxAppointments) {
        if (app[i].patientNumber < 1) {
            found = 1;
        }
        i++;
    }
    return i;
}


int timeSlotAvailable(struct Date date, struct Time time, struct Appointment* app, int maxAppointments) {
    int i, slotAvailable = 0;

    for (i = 0; i < maxAppointments; i++) {
        // Checking if time slot is available
        if (date.year == app[i].date.year && date.month == app[i].date.month && date.day == app[i].date.day && time.hour == app[i].time.hour && time.min == app[i].time.min) {
            slotAvailable = 1;
        }
    }

    return slotAvailable;
}
    //////////////////////////////////////
    // USER INPUT FUNCTIONS
    //////////////////////////////////////

    // Get user input for a new patient record
    void inputPatient(struct Patient * patient)
    {

        printf("Name  : ");
        // scanf("%[^\n]s", patient->name);
        inputCString(patient->name, 1, 15);
        printf("\n");
        inputPhoneData(&patient->phone);
    }

    // Get user input for phone contact information
    void inputPhoneData(struct Phone * phone)
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

            inputCStringNumbers(phone->number, 10, 10);
        }
        printf("\n");
    }
    int nextAvailableIndex(struct Appointment * appoints, int max)
    {
        int i;
        int flag = 1;
        while (flag == 1 && i < max)
        {
            if (appoints[i].patientNumber < 1)
            {
                flag = 0;
            }
            i++;
        }
        return i;
    }
    /////////////////////////////////////
    // FILE FUNCTIONS
    //////////////////////////////////////

    // Import patient data from file into a Patient array (returns # of records read)
    int importPatients(const char *datafile, struct Patient patients[], int max)
    {
        int i = 0;
      
        FILE *fp = fopen(datafile, "r");
        if (fp != NULL)
        {
            while (i < max)
            {
                fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number);
                i++;
            }
            fclose(fp);
            fp = NULL;
        }
        else
        {
            printf("Error: unable to open a file ");
        }
        return i;
    }

    // Import appointment data from file into an Appointment array (returns # of records read)
    int importAppointments(const char *datafile, struct Appointment appoints[], int max)
    {
        int i = 0;
        
        FILE *fp = fopen(datafile, "r");
        if (fp != NULL)
        {
            while (fscanf(fp, "%4d,%4d,%1d,%2d,%2d,%02d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) != EOF)
            {

                i++;
            }
            fclose(fp);
            fp = NULL;
        }
        else
        {
            printf("Error: unable to open a file");
        }
        return i;
    }
