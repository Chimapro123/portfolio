#include <stdio.h>
#include <string.h>

// #define STUDENT_FILE "students.dat"
// #define TEACHER_FILE "teachers.dat"
// #define AUX_FILE "aux.dat"

struct Student
{
    char name[50];
    char id[20];
    char age[20];
    char courses[100];
};
struct Teacher
{
    char name[50];
    char id[20];
    char age[20];
    char subjects[100];
};
struct AUX
{
    char name[50];
    char id[20];
    char age[30];
    char duty[50];
    float salary;
};

int main()
{
    struct Student students[100];
    struct Teacher teachers[100];
    struct AUX workers[50];
    int stdcount = 0;
    int tchcount = 0;
    int auxcount = 0;
    // void save_students_to_file()
    // {
    //     FILE *file =
    // }
    char courses[20];

    int option;
    int choice;
    char stdsearchID[20];
    char tchsearchID[20];
    char auxsearchID[20];

    int foundstd;
    int foundtch;
    int foundaux;

    do
    {
        printf("\n===== DAVI's UNI MANAGEMENT SYSTEM =====\n");
        printf("1. Student Portal\n");
        printf("2. Teacher Portal\n");
        printf("3. Auxilary worker\n");
        printf("4. About DAVI's University");
        printf("5. Exit the system\n");

        printf("\n=====Enter an option to view your portal: ========\n");
        scanf("%d", &option);

        switch (option)
        {

        case 1:
            // Wrapping student data by his royal highness Chiboy Yagi
            printf("\n==WELCOME TO THE STUDENT MANAGEMENT PORTAL==\n");
            printf("These are our available Options......\n");
            printf("1. Add Students\n");
            printf("2. View Students\n");
            printf("3. Search Students\n");
            printf("4. exit Students portal..........\n");

            printf("\nEnter choice: \n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1: // add student
                if (stdcount >= 100)
                {
                    printf("Student database is full!\n");
                    break;
                }
                printf("\nEnter Student Name: ");
                scanf(" %[^\n]", students[stdcount].name);

                printf("Enter Student ID: ");
                scanf("%s", students[stdcount].id);

                printf("Enter Age: ");
                scanf("%s", students[stdcount].age);

                printf("Enter Student courses: ");
                scanf(" %[^\n]", students[stdcount].courses);

                stdcount++;
                printf("Student Added Successfully!\n");
                break;

                // ______________________________________________________________________________________________
            case 2: // to show the registered students
                if (stdcount == 0)
                {
                    printf("\nNo students available for now.\n");
                }
                else
                {
                    printf("\n--- STUDENT RECORDS ---\n");

                    for (int i = 0; i < stdcount; i++)
                    {
                        printf("\nStudent %d\n", i + 1);
                        printf("Name: %s\n", students[i].name);
                        printf("ID: %s\n", students[i].id);
                        printf("Age: %s\n", students[i].age);
                        printf("Studying: %s", students[i].courses);
                    }
                }
                break;
                // _______________________________________________________________________________________________
            case 3: // allows user to search for the student by inputing the student ID
                foundstd = 0;

                printf("Enter Student ID to Search: ");
                scanf("%s", stdsearchID);

                for (int i = 0; i < stdcount; i++)
                {
                    if (strcmp(students[i].id, stdsearchID) == 0)
                    {
                        printf("\nStudent Found!\n");
                        printf("Name: %s\n", students[i].name);
                        printf("ID: %s\n", students[i].id);
                        printf("Age: %s\n", students[i].age);
                        printf(" Studying: %s\n", students[i].courses);
                        foundstd = 1;
                        break;
                    }
                }

                if (foundstd == 0)
                {
                    printf("Student not found.\n");
                }
                break;
                // ______________________________________________________________________________________________
            case 4: // Exits the program
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
            }
            break;
            // __________________________________________________________________________________________________
        case 2: // Teacher's Portal......
            printf("\n===== TEACHERS MANAGEMENT PORTAL =====\n");
            printf("1. Add Teachers\n");
            printf("2. View Teachers\n");
            printf("3. Search for a Teachers\n");
            printf("4. Exit\n");
            printf("\nEnter Your Choice: \n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                if (tchcount >= 100)
                {
                    printf("Teacher database is full!\n");
                    break;
                }

                printf("\nEnter Teacher's Name: ");
                scanf(" %[^\n]", teachers[tchcount].name);

                printf("Enter Teacher ID: ");
                scanf("%s", teachers[tchcount].id);

                printf("Enter Age: ");
                scanf("%s", teachers[tchcount].age);

                printf("Enter Teacher Subjects ");
                scanf(" %[^\n]", teachers[tchcount].subjects);

                tchcount++;
                printf("Teacher Added Successfully!\n");
                break;
                // ___________________________________________________________________________________________________
            case 2: // to view teachers
                if (tchcount == 0)
                {
                    printf("\n======== No Teachers Recorded for now!======\n");
                }
                else
                {
                    printf("\n--- TEACHERS RECORDED ---\n");

                    for (int i = 0; i < tchcount; i++)
                    {
                        printf("\nTeacher %d\n", i + 1);
                        printf("Name: %s\n", teachers[i].name);
                        printf("ID: %s\n", teachers[i].id);
                        printf("Age: %s\n", teachers[i].age);
                        printf("Taking: %s\n", teachers[i].subjects);
                    }
                }
                break;
                // _________________________________________________________________________________________________
            case 3: // Searching for teachers
                foundtch = 0;

                printf("Enter Teacher's ID to Search: ");
                scanf("%s", tchsearchID);

                for (int i = 0; i < tchcount; i++)
                {
                    if (strcmp(teachers[i].id, tchsearchID) == 0)
                    {
                        printf("\n Teacher Found!\n");
                        printf("Name: %s\n", teachers[i].name);
                        printf("ID: %s\n", teachers[i].id);
                        printf("Age: %s\n", teachers[i].age);
                        printf("Taking: %s\n", teachers[i].subjects);
                        foundtch = 1;
                        break;
                    }
                }

                if (foundtch == 0)
                {
                    printf("Teacher not found.\n");
                }
                break;
            case 4: // Exits the program
                printf("Exiting Program...\n");
                break;
            default:
                printf("\nYou entered the wrong Input ");
            }
            break;
        case 3: // AUXILARY WORKER'S PORTAL OUTTER SWITCH CASE
            printf("\n=======Welcome to the Auxilary worker's Portal=======\n");
            printf("1. Add Workers\n");
            printf("2. View Workers\n");
            printf("3. Search for a Worker\n");
            printf("4. Exit\n");
            printf("\nEnter Your Choice: \n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                if (auxcount >= 100)
                {
                    printf("Auxilary database is full!\n");
                    break;
                }
                printf("\nEnter your name: ");
                scanf(" %[^\n]", workers[auxcount].name);

                printf("\nEnter your Age: ");
                scanf("%s", workers[auxcount].age);

                printf("\nEnter your ID: ");
                scanf("%s", workers[auxcount].id);

                printf("\nEnter your duty: ");
                scanf(" %[^\n]", workers[auxcount].duty);

                printf("\nHow much are you getting paid?");
                scanf("%f", &workers[auxcount].salary);

                auxcount++;
                printf("=====Auxilary worker recieved====");

                break;
            case 2: // to view current auxilary worker;
                if (auxcount == 0)
                {
                    printf("\n==No workers recorded==\n");
                }
                else
                {

                    printf("\n=====Our registered worker====\n");
                    for (int i = 0; i < auxcount; i++)
                    {
                        printf("=====Our registered worker====\n");
                        printf("Worker's name: %s\n", workers[i].name);
                        printf("Worker's Age: %s\n", workers[i].age);
                        printf("Worker's ID: %s\n", workers[i].id);
                        printf("Worker's Duty: %s\n", workers[i].duty);
                        printf("Worker's Salary: %.2f\n", workers[i].salary);
                    }
                }
                break;
            case 3: // searching workers................
                foundaux = 0;
                printf("Enter Worker's ID to Search: \n");
                scanf("%s", auxsearchID);

                for (int i = 0; i < auxcount; i++)
                {
                    if (strcmp(workers[i].id, auxsearchID) == 0)
                    {
                        printf("\n Worker Found!\n");
                        printf("Name: %s\n", workers[i].name);
                        printf("ID: %s\n", workers[i].id);
                        printf("Age: %s\n", workers[i].age);
                        printf("Salary: %.2f\n", workers[i].salary);
                        foundaux = 1;
                        break;
                    }
                }
                if (foundaux == 0)
                {
                    printf("No workers Found");
                }
                break;
            case 4:
                printf("Exiting portal................33....................");
                break;
            default:
                printf("Worng input.........");
            }
            break; // closing outter case 4.........
        case 4:    // more about school....
            printf("1. to view our Courses\n");
            printf("2. to view teachers\n");
            printf("3. to view Accomodation\n");
            printf("Enter a choice\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("* study CPISM for 6 months to learn everything on web development\n");
                printf("* ADSE (Advanced Diploma in Software Engineering) 1year course: to learn everything on software engineering \n");
                printf("* Certified Network Specialist CNS\n");
                printf("* Multimedia Specialist Course, learn Everything about Animations and multimedia\n");
                printf("* You can choose to sign up and become one of us\n JUST EXIT THIS PORTAL AND ENTER THE STUDENT PORTAL\n");

                break;

            case 2:

                if (tchcount == 0)
                {
                    printf("\n==No Teachers recorded for now==\n");
                }
                else
                {

                    printf("\n--- TEACHERS RECORDED ---\n");

                    for (int i = 0; i < tchcount; i++)
                    {
                        printf("\nTeacher %d\n", i + 1);
                        printf("Name: %s\n", teachers[i].name);
                        printf("ID: %s\n", teachers[i].id);
                        printf("Age: %s\n", teachers[i].age);
                        printf("Taking: %s\n", teachers[i].subjects);
                    }
                    break;
                }
            case 3:
                printf("enter your course: ");

                scanf(" %[^\n]", courses);
                printf("We do not have accomodations for staffs\n");
                printf("%s Studio apartment available for 100,000 naira more\n", courses);
                break;

            default:
                printf("Wrong Input");
            }

            break; // closing case 5 from outter switch case;
        case 5:
            printf("\nExiting the system....................\n");

            break;

        default:

            printf("wrong input.........\n");
            break;
        }

    } while (option != 5);

    return 0;
}