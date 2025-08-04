#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define t_std 500
// the regis code need for registration for the teachers
#define Regcode "IIUC95Auth"

// Global Variables:
int n, s;
int z;
char Tid[100];
char Tname[100];
char Tpass[100];
char fname[100];
char lname[100];
char id[100];
char pass[20];
char regT[20];
char file_id[100], file_pass[100];

// Functions
void class_check();
void loginT();
void regis();
void login();
void OptT();
void stdt(char* username);
void regisT();
void room_check();

// Structure
struct student
{
    char fname[100];
    char lname[100];
    char id[100];
    char pass[20];
};

// Function Start

void regis()
{
    system("cls");
    printf("----Welcome To IIUC Student Portal Registration Page----\n\n");
    FILE *log;

    printf("\n=== Registration ===\n");
    printf("Enter Your Full Name: ");
    fgets(fname, sizeof(fname), stdin);
    fname[strcspn(fname, "\n")] = 0;
    printf("Enter Your ID Name: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;
    printf("Enter Your Password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = 0;

    log = fopen("userinfo.txt", "a");
    if (log == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(log, "%s %s %s\n", fname, id, pass);
    fclose(log);
    printf("\nRegistration successful!\n\n");
    printf("Your Username: %s\n", id);
    printf("Your Password: %s\n\n", pass);
    printf("To Login press 2\n");
    scanf("%d", &n);
    if (n == 2)
    {
        login();
    }
}

void login()
{
    system("cls");

    printf("----Welcome To IIUC Student Portal Login Page----\n\n");
    while (1) {
        printf("\n=== Login ===\n");
        printf("Enter username: ");
        scanf("%s", id);
        printf("Enter password: ");
        scanf("%s", pass);

        FILE *log;
        log = fopen("userinfo.txt", "r");
        if (log == NULL)
        {
            printf("Error opening file or no registered users.\n");
            return;
        }
        int found = 0;
        char temp_fname[100], temp_id[100], temp_pass[100];
        while (fscanf(log, "%s %s %s", temp_fname, temp_id, temp_pass) != EOF)
        {
            if (strcmp(id, temp_id) == 0 && strcmp(pass, temp_pass) == 0)
            {
                found = 1;
                break;
            }
        }
        fclose(log);
        if (found)
        {
            system("cls");
            printf("Login successful! Welcome, %s\n\n\n\n", id);
            stdt(id);
            break;
        }
        else
        {
            system("cls");
            printf("Login failed. Invalid username or password.\n");
            printf("Press 1 to try again, 0 to go back: ");
            int retry;
            scanf("%d", &retry);
            if (retry == 0) break;
        }
    }
}

void loginT()
{
    system("cls");
    printf("----Welcome to Teacher's Login----\n\n");
    int T = 0;
    while (1) {
        printf("Enter username: ");
        scanf("%s", id);
        printf("Enter password: ");
        scanf("%s", pass);
        FILE *ln;
        ln = fopen("teacherinfo.txt", "r");
        if (ln == NULL)
        {
            printf("Error opening file or no registered users.\n");
            return;
        }
        int found = 0;
        char temp_name[100], temp_id[100], temp_pass[100];
        while (fscanf(ln, "%s %s %s", temp_name, temp_id, temp_pass) != EOF)
        {
            if (strcmp(id, temp_id) == 0 && strcmp(pass, temp_pass) == 0)
            {
                found = 1;
                break;
            }
        }
        fclose(ln);

        if (found)
        {
            T = 1;
            printf("Login successful! Welcome, %s\n", id);
            break;
        }
        else
        {
            printf("Login failed. Invalid username or password.\n");
            printf("Press 1 to try again, 0 to go back: ");
            int retry;
            scanf("%d", &retry);
            if (retry == 0) break;
        }
    }
    if (T == 1)
    {
        OptT();
    }
}

void OptT()
{
    system("cls");
    FILE *not;
    not = fopen("notice.txt", "w");
    if (not != NULL) {
        fclose(not);
    }

    int T1;
    char notice[100];
    while (1) {
        printf("1.Room Availability\n");
        printf("2.Class Checker\n");
        printf("3.Back to LOg out\n");
        scanf("%d", &T1);
        if (T1 == 1)
        {
            room_check();
            printf("Press 0 to back\n");
            printf("Press 1 to go to Log out\n");
            scanf("%d", &z);
            if (z == 0)
            {
                system("cls");
                continue;
            }
            else if(z == 1)
            {
                system("cls");
                return;
            }
            else
            {
                system("cls");
                printf("Invalid Input \nTry Again : ");
                continue;
            }
        }
        if (T1 == 2)
        {
            class_check();
            printf("Press 0 to back\n");
            printf("Press 1 to go to Log out\n");
            scanf("%d", &z);
            if (z == 0)
            {
                system("cls");
                continue;
            }
            else if(z == 1)
            {
                system("cls");
                return;
            }
            else
            {
                system("cls");
                printf("Invalid Input \nTry Again : ");
                continue;
            }
        }
        if (T1 == 3)
        {
            return;
        }
    }
}

void stdt(char* username)
{
    system("cls");
    printf("\nWelcome %s\n", username);
    printf("Semester : 1st\n\n\n");

    while (1) {
        printf("1.Room Check\n");
        printf("2.Class Check\n");
        printf("3.Registered Subject\n");
        printf("4.Teacher's List\n");
        printf("5.Back to Log out\n\n");

        printf("Choose From 1-5 : ");
        scanf("%d", &s);
        if (s < 1 || s > 5)
        {
            system("cls");
            printf("Wrong Input .....\nTry Again\n");
            continue;
        }
        if (s == 1)
        {
            printf("Room Check :\n");
            room_check();

            printf("Press 0 to back\n");
            printf("Press 1 to go to Log out\n");
            scanf("%d", &z);
            if (z == 0)
            {
                system("cls");
                continue;
            }
            else if(z == 1)
            {
                system("cls");
                return;
            }
            else
            {
                system("cls");
                printf("Invalid Input \nTry Again : ");
                continue;
            }
        }
        if (s == 3)
        {
            printf("   Credit Hour |Registered Subjects:\n\n");
            printf("1.     3       |Computer Programming 1\n");
            printf("2.    1.5      |Computer Programming 1 Lab\n");
            printf("3.     3       |Basic Electrical Engineering\n");
            printf("4.    1.5      |Basic Electrical Engineering Lab\n");
            printf("5.     2       |Advanced English\n");
            printf("6.     1       |Text of Ethics and Morality \n");
            printf("7.     3       |Mathematics I (Differential and Integral Calculus)\n");
            printf("8.     3       |Physics I (Mechanics, Waves, Heat and Thermodynamics)\n");

            printf("Press 0 to back\n");
            printf("Press 1 to go to Log out\n");
            scanf("%d", &z);
            if (z == 0)
            {
                system("cls");
                continue;
            }
            else if(z == 1)
            {
                system("cls");
                return;
            }
            else
            {
                system("cls");
                printf("Invalid Input \nTry Again : ");
                continue;
            }
        }
        if (s == 4)
        {
            printf("Teacher's Info :\n\n\n");
            printf("Teacher's Name   |         Email Address     |  Phone Number\n\n");
            printf("Jamil As-ad      | jamilasad1@gmail.com      |  01626890190\n");
            printf("Sahariar Reza    | Sahariarp@gmail.com       |  01521328094\n");
            printf("Md.Rashedul Islam| rashed_math@gmail.com     |  01717121186\n");
            printf("Kafil Uddin      | mdkafil_iiuc@gmail.com    |  01819101372\n");
            printf("Abdullah Al Mamun| mamun.phys@gmail.com      |  01521483685\n");

            printf("Press 0 to back\n");
            printf("Press 1 to go to LOg out\n");

            scanf("%d", &z);
            if (z == 0)
            {
                system("cls");
                continue;
            }
            else if(z == 1)
            {
                system("cls");
                return;
            }
            else
            {
                system("cls");
                printf("Invalid Input \nTry Again : ");
                continue;
            }
        }
        if (s == 2)
        {
            class_check();

            printf("Press 0 to back\n");
            printf("Press 1 to go to Log out\n");

            scanf("%d", &z);
            if (z == 0)
            {
                system("cls");
                continue;
            }
            else if(z == 1)
            {
                system("cls");
                return;
            }
            else
            {
                system("cls");
                printf("Invalid Input \nTry Again : ");
                continue;
            }
        }
        if (s == 5)
        {
            return;
        }
    }
}

void regisT()
{
    system("cls");
    char chk[20];
    int pck = 3;
    strcpy(chk, Regcode);

    printf("Welcome to Registration\n\n");
    while (pck > 0) {
        printf("Enter The 10 Digit Code Provided By the Authority to registration :\n");
        getchar(); // Clear buffer
        fgets(regT, sizeof(regT), stdin);
        regT[strcspn(regT, "\n")] = 0;
        if (strcmp(regT, chk) == 0)
        {
            printf("Verification Successful\nNow You can Proceed\n");
            system("cls");
            printf("----Welcome To Teacher Registration Page----\n\n");
            FILE *Tea;

            printf("\n=== Registration ===\n");
            printf("Enter Your Name: ");
            fgets(Tname, sizeof(Tname), stdin);
            Tname[strcspn(Tname, "\n")] = 0;
            printf("Enter Your ID Name: ");
            fgets(Tid, sizeof(Tid), stdin);
            Tid[strcspn(Tid, "\n")] = 0;
            printf("Enter Your Password: ");
            fgets(Tpass, sizeof(Tpass), stdin);
            Tpass[strcspn(Tpass, "\n")] = 0;

            Tea = fopen("teacherinfo.txt", "a");
            if (Tea == NULL) {
                printf("Error opening file for writing.\n");
                return;
            }
            fprintf(Tea, "%s %s %s\n", Tname, Tid, Tpass);
            fclose(Tea);
            printf("\nRegistration successful!\n\n");
            printf("Your Username: %s\n", Tid);
            printf("Your Password: %s\n\n", Tpass);

            while (1) {
                printf("To Login press 2\n");
                scanf("%d", &n);
                if (n == 2)
                {
                    loginT();
                    break;
                }
                else
                {
                    printf("Try Again\n\n");
                }
            }
            break;
        }
        else
        {
            pck--;
            system("cls");
            printf("You have %d chances\n", pck);

            if (pck == 0)
            {
                system("cls");
                printf("You Have Been Blocked\nContact In 'ACAD' ");
                return;
            }
        }
    }
}

void room_check()
{
    system("cls");
    FILE *fp = NULL;
    char line[555];
    char room[50];
    int period;
    int d;

    // Ask user input
    printf("Enter Day (1-5)\n");
    printf("1.Saturday  2.Sunday  3.Monday  4.Tuesday  5.Wednesday\n");
    scanf("%d", &d);
    printf("Enter period number (1-6): ");
    scanf("%d", &period);
    printf("Enter room name (e.g., C105): ");
    scanf("%s", room);

    // Days
    if (d == 1)
    {
        fp = fopen("saturday.txt", "r");
    }
    else if (d == 2)
    {
        fp = fopen("sunday.txt", "r");
    }
    else if (d == 3)
    {
        fp = fopen("monday.txt", "r");
    }
    else if (d == 4)
    {
        fp = fopen("tuesday.txt", "r");
    }
    else if (d == 5)
    {
        fp = fopen("wednesday.txt", "r");
    }
    else
    {
        printf("Invalid day selection.\n");
        return;
    }

    if (!fp)
    {
        printf("Could not open routine file.\n");
        return;
    }

    // Skip header line
    fgets(line, sizeof(line), fp);

    int current = 0, found = 0;
    while (fgets(line, sizeof(line), fp))
    {
        current++;

        // If we are at the requested period
        if (current == period)
        {
            line[strcspn(line, "\n")] = 0; // Remove newline

            // Split using semicolon
            char *time = strtok(line, ";");
            char *am = strtok(NULL, ";");
            char *bm = strtok(NULL, ";");
            char *cm = strtok(NULL, ";");

            // Check if the room exists in this period
            if ((am && strstr(am, room)) || (bm && strstr(bm, room)) || (cm && strstr(cm, room)))
            {
                printf("\nRoom %s is OCCUPIED in period %d.\n", room, period);
                found = 1;
            }
            else
            {
                printf("\nRoom %s is EMPTY in period %d.\n", room, period);
            }
            break;
        }
    }

    fclose(fp);

    // Handle invalid period
    if (current < period)
    {
        printf("\nInvalid period number. No such row in the file.\n");
    }
}

void class_check()
{
    FILE *fp = NULL;
    char line[256];
    char section[10];
    int period;
    int d;

    // Ask user for input
    printf("Enter Day (1-5)\n");
    printf("1.Saturday  2.Sunday  3.Monday  4.Tuesday  5.Wednesday\n");
    scanf("%d", &d);
    printf("Enter your section (1AM/1BM/1CM): ");
    scanf("%s", section);
    printf("Enter period number (1-6): ");
    scanf("%d", &period);

    // Days
    if (d == 1)
    {
        fp = fopen("saturday.txt", "r");
    }
    else if (d == 2)
    {
        fp = fopen("sunday.txt", "r");
    }
    else if (d == 3)
    {
        fp = fopen("monday.txt", "r");
    }
    else if (d == 4)
    {
        fp = fopen("tuesday.txt", "r");
    }
    else if (d == 5)
    {
        fp = fopen("wednesday.txt", "r");
    }
    else
    {
        printf("Invalid day selection.\n");
        return;
    }

    if (!fp)
    {
        printf("Could not open routine file.\n");
        return;
    }

    // Read header (ignore first line)
    fgets(line, sizeof(line), fp);

    int current = 0;
    while (fgets(line, sizeof(line), fp))
    {
        current++;
        if (current == period)
        {
            // Remove newline
            line[strcspn(line, "\n")] = 0;

            // Split CSV line
            char *token = strtok(line, ";");
            char *time = token;
            char *am = strtok(NULL, ";");
            char *bm = strtok(NULL, ";");
            char *cm = strtok(NULL, ";");

            printf("\nTime: %s\n", time);
            if (strcmp(section, "1AM") == 0)
                printf("Class: %s\n", am);
            else if (strcmp(section, "1BM") == 0)
                printf("Class: %s\n", bm);
            else if (strcmp(section, "1CM") == 0)
                printf("Class: %s\n", cm);
            else
                printf("Invalid section!\n");
            break;
        }
    }

    fclose(fp);
}

// Main Function

int main()
{
    system("cls");

    while (1) {
        printf("\033[1;32mINTERNATIONAL ISLAMIC UNIVERSITY CHITTAGONG\033[0m\n\n\n");
        printf("** Press 1 for Registration(Student)  **\n");
        printf("** Press 2 for Login(Student)         **\n");
        printf("** Press 3 for Login(Teacher)         **\n");
        printf("** Press 4 for Registration(Teacher)  **\n");
        printf("** Press 5 for (Exit)                 **\n");

        struct student a[t_std];

        FILE *log;
        log = fopen("userinfo.txt", "a");
        if (log != NULL) {
            fclose(log);
        }

        scanf("%d", &n);
        getchar();

        if (n == 1)
        {
            regis();
        }
        else if (n == 2)
        {
            login();
        }
        else if (n == 3)
        {
            loginT();
        }
        else if (n == 4)
        {
            regisT();
        }
        else if (n == 5)
        {
            system("cls");
            printf("Exiting............\n");
            break;
        }
        else
        {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
