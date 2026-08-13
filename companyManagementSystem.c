#include <stdio.h>
#include <string.h>

struct Borrower
{
    char fullname[100];
    char age[100];
    char idtype[50];
    float hwmuch;
    char Occupa[30];
    char bvn[12];
    float payment;
    float collworth; // collateral worth
    float returnbor; // Calculates the outcome of loans
    int time;
    float elig;
    float loan;
};
struct Investor
{
    char fullname[100];
    char age[20];
    float hwmuch;
    char idtype[20];
    float returninv; // calculate the outcome of investments
    char Occupa[30];
    char bvn[30];
    int time;
    float withdraw;
    float loan;
    int timloan;
    float payment;
};
int main()
{
    struct Borrower borrowers[100];
    struct Investor investors[200];
    int invcount = 0; // instead of useing maxcount;
    int borcount = 0;

    int option;
    int choice;

    char searchbvnbor[20];
    char searchbvninv[20];

    char currency = '$';
    int foundbor;
    int foundinv;

    do
    {
        printf("\n===========Welcome To YAGII's_CARES Management system======\n");
        printf("1. To View the Loan_Portal\n");
        printf("2. To View our Investment_Portal\n");

        printf("3. Exit the system\n");
        printf("\n=====Enter an option to view a portal: ========\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\n=====Welcome to YAGII's_CARES where every client is valued=======\n"); // loan portal
            printf("1. See our Offers \n");
            printf("2. Create Account\n");
            printf("3. Search profiles\n");
            printf("4. View profile\n");
            printf("5. Exit The System");
            printf("\nEnter a  choice to start\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1: // TO VIEW OFFERS......
                printf("Enter loan amount: ");
                scanf("%f", &borrowers[borcount].hwmuch);

                printf("For how many years: ");
                scanf("%d", &borrowers[borcount].time);
                //  to calcculate the inpput by 15%
                borrowers[borcount].returnbor = borrowers[borcount].hwmuch +
                                                (borrowers[borcount].hwmuch * 0.15 * borrowers[borcount].time);

                printf("Your total repayment for %dyear(s) is %c%.2f\n", borrowers[borcount].time, currency, borrowers[borcount].returnbor);
                break;

            case 2: // Creating account
                printf("\nEnter your name: ");
                scanf(" %[^\n]", borrowers[borcount].fullname);

                printf("Enter your ID type: ");
                scanf(" %[^\n]", borrowers[borcount].idtype);

                printf("What do you do for a living: ");
                scanf(" %[^\n]", borrowers[borcount].Occupa);

                printf("Enter your age: ");
                scanf(" %[^\n]", borrowers[borcount].age);
                do
                {
                    printf("Enter Your BVN number: ");
                    scanf("%11s", borrowers[borcount].bvn);

                    if (strlen(borrowers[borcount].bvn) != 11)
                    {

                        printf("\n==== BVN must be exactly 11 digits! ====\n");
                    }

                } while (strlen(borrowers[borcount].bvn) != 11);

                do
                {
                    printf("Enter your collateral's worth: ");

                    if (scanf("%f", &borrowers[borcount].collworth) != 1)
                    {
                        printf("Please enter a valid number.\n");

                        while (getchar() != '\n')
                            ;

                        // TO Clear invalid input
                        borrowers[borcount].collworth = 0;
                        continue;
                    }

                    if (borrowers[borcount].collworth <= 150000.00)
                    {
                        printf("Not Qualified\n");
                        printf("\n=======your collateral worth is too low===\n");
                    }
                } while (borrowers[borcount].collworth <= 150000.00);

                borrowers[borcount].elig = borrowers[borcount].collworth / 2.0; // floats divide floats btetter
                printf("you are eligible to %c%.2f\n", currency, borrowers[borcount].elig);

                do
                {
                    printf("Enter loan amount:");
                    scanf("%f", &borrowers[borcount].loan);
                    if (borrowers[borcount].loan >= borrowers[borcount].elig)
                    {
                        printf("Loan amount should not exceed eLigibled value\n");
                        printf("your eligible amount entry must be %c%.2f\n", currency, borrowers[borcount].elig);
                    }

                } while (borrowers[borcount].loan >= borrowers[borcount].elig);
                printf("\nFor how many years: ");
                scanf("%d", &borrowers[borcount].time);

                //  to calcculate the inpput by 15%

                borrowers[borcount].returnbor = borrowers[borcount].loan +
                                                (borrowers[borcount].loan * 0.15 * borrowers[borcount].time);

                printf("Your total repayment for %dyear(s) is %c%.2f\n", borrowers[borcount].time, currency,
                       borrowers[borcount].returnbor);

                borcount++;
                printf("Account Added Successfully\n");
                printf("\n\n");
                printf("Processing loan............................................\n");
                printf("\n\n");
                printf("Congratulations!!!");

                break;

            case 3: // to search for borrower
                foundbor = 0;

                printf("To find Profile Enter Your Bank Verification Number: \n");
                scanf("%s", searchbvnbor);

                for (int i = 0; i < borcount; i++)
                {
                    if (strcmp(borrowers[i].bvn, searchbvnbor) == 0)
                    {
                        printf("\n===== Individual Found!! =====\n");
                        printf("\nBorrower %d\n", i + 1);
                        printf("Name: %s\n", borrowers[i].fullname);
                        printf("age: %s\n", borrowers[i].age);

                        printf("Occupation: %s\n", borrowers[i].Occupa);
                        printf("Debt: %c%.2f\n", currency, borrowers[i].loan);
                        printf("Loan after added interests: %c%.2f\n", currency, borrowers[i].returnbor);
                        printf("Seasons/time: %dyear(s)\n", borrowers[i].time);

                        foundbor = 1;
                        break;
                    }
                }

                if (foundbor == 0)
                {
                    printf("No such account in our system: \n");
                }
                break;
            case 4: // to view profiles
                if (borcount == 0)
                {
                    printf("===== No recorded loans ======\n");
                }
                else
                {
                    printf(" OUR RECORDS ARE: \n");
                    for (int i = 0; i < borcount; i++)
                    {
                        printf("\n===== Individual Found!! =====\n");
                        printf("\nBorrower %d\n", i + 1);
                        printf("Name: %s\n", borrowers[i].fullname);
                        printf("age: %s\n", borrowers[i].age);
                        printf("Submitted Identity: %s\n", borrowers[i].idtype);
                        printf("Bank Verification Number: %s\n", borrowers[i].bvn);
                        printf("Occupation: %s\n", borrowers[i].Occupa);
                        printf("Debt: %c%.2f\n", currency, borrowers[i].loan);
                        printf("Loan after added interests: %c%.2f\n", currency, borrowers[i].returnbor);
                        printf("Seasons/time: %dyear(s)\n", borrowers[i].time);
                    }
                }
                break;
            case 5:
                printf("Have a Nice Day sir/ma.....\n");
                break;

            default:
                printf("\n=====WRONG INPUT======\n");
            }
            break;
            // ___________________________________________________________________

        case 2: // portal option two for investment
            printf("====\nWarm Welcomes to Our Investment Portal @YAGII's_CARES====\n enter choice to continue: ");
            printf("\n1. See our Offers \n");
            printf("2. Create Account\n");
            printf("3. Search profiles\n");
            printf("4. View profiles\n");
            printf("5. Take a loan\n");
            printf("6. Oppotunities \n");
            printf("7. Exit The System");
            printf("\n\nEnter a  choice to start\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1: // to view investment offers
                printf("to view our offers enter An Amount: ");
                scanf("%f", &investors[invcount].hwmuch);

                printf("\nFor How Long Would Love To Watch Your Investment Grow: ");
                scanf("%d", &investors[invcount].time);

                investors[invcount].returninv = investors[invcount].hwmuch +
                                                (investors[invcount].hwmuch * 0.15 * investors[invcount].time);

                printf("your Revenue after %dyear(s) is %c%.2f\n", investors[invcount].time, currency, investors[invcount].returninv);
                printf("\nTo proceed enter the next portal ");
                // break;

            case 2: // Create investment account.....

                printf("\n====== Welcome once again investor ======\n");
                printf("Enter your name to sign-up");
                printf("\nEnter your name: ");
                scanf(" %[^\n]", investors[invcount].fullname);

                printf("\nWelcome mr/mrs %s YAGII's_CARES\n", investors[invcount].fullname);

                printf("\nEnter your age: ");
                scanf(" %[^\n]", investors[invcount].age);

                printf("\nEnter ID type: ");
                scanf(" %[^\n]", investors[invcount].idtype);

                printf("\nEnter your Occupation: ");
                scanf(" %[^\n]", investors[invcount].Occupa);

                do
                {
                    printf("\nEnter Your BVN number: ");
                    scanf("%11s", investors[invcount].bvn);

                    if (strlen(investors[invcount].bvn) != 11)
                    {

                        printf("\n==== BVN must be exactly 11 digits! ====\n");
                    }

                } while (strlen(investors[invcount].bvn) != 11);

                printf("\nHow much would you like to invest with us: ");
                scanf("%f", &investors[invcount].hwmuch);

                printf("\nFor how long: ");
                scanf("%d", &investors[invcount].time);

                investors[invcount].returninv = investors[invcount].hwmuch +
                                                (investors[invcount].hwmuch * 0.15 * investors[invcount].time);

                printf("your Revenue after %dyear(s) is %c%.2f\n", investors[invcount].time, currency, investors[invcount].returninv);

                invcount++;
                printf("Investor added Successfully");
                break;
            case 3: // to search for investor profile...

                foundinv = 0;

                do
                {
                    printf("\nEnter Your BVN number: ");
                    scanf("%11s", investors[invcount].bvn);

                    if (strlen(investors[invcount].bvn) != 11)
                    {

                        printf("\n==== BVN must be exactly 11 digits! ====\n");
                    }

                } while (strlen(investors[invcount].bvn) != 11);

                for (int i = 0; i < invcount; i++)
                {
                    if (strcmp(investors[i].bvn, searchbvninv) == 0)
                    {
                        printf("\n===== Individual Found!! =====\n");
                        printf("\n====Investor %d\n", i + 1);
                        printf("Investor's fullName: %s\n", investors[i].fullname);
                        printf("Investor's age: %s\n", investors[i].age);
                        printf("Submitted Identity type: %s\n", investors[i].idtype);
                        printf("Bank Verification Number: %s\n", investors[i].bvn);
                        printf("Investor's Occupation: %s\n", investors[i].Occupa);
                        printf("%s Invested a total of: %c%.2f", investors[i].fullname, investors[i].hwmuch);
                        printf("Investement after added interests: %c%.2f\n", currency, investors[i].returninv);
                        printf("Seasons/time: %dyear(s)\n", investors[i].time);
                        foundinv = 1;
                        break;
                    }
                }
                if (foundinv == 0)
                {
                    printf("\nNot an existing Account\n");
                }
                break;

            case 4: // view resgistered profiles

                if (invcount == 0)
                {
                    printf("\nThere currently no registered accounts in our system =======\n");
                }
                else
                {
                    printf("Investor's records are\n");

                    for (int i = 0; i < invcount; i++)
                    {
                        printf("\nInvestor %d\n", i + 1);
                        printf("Investor's fullName: %s\n", investors[i].fullname);
                        printf("Investor's age: %s\n", investors[i].age);
                        printf("Submitted Identity type: %s\n", investors[i].idtype);
                        printf("Bank Verification Number: %s\n", investors[i].bvn);
                        printf("Investor's Occupation: %s\n", investors[i].Occupa);
                        printf("%s Invested a total of: %c%.2f", investors[i].fullname, currency, investors[i].hwmuch);
                        printf("Investement after added interests: %c%.2f\n", currency, investors[i].returninv);
                        printf("Seasons/time: %dyear(s)\n", investors[i].time);
                    }
                }
                break;
            case 5: // investor take a loan

                printf("\n======= Investors get a 5(percent) discount for every loan =====\n");
                printf("\nEnter your bvn if you have an account with YAGII_CARES company");
                foundinv = 0;
                scanf("%11s", searchbvninv);
                for (int i = 0; i < invcount; i++)
                {
                    if (strcmp(investors[i].bvn, searchbvninv) == 0)
                    {
                        printf("\n===== Individual Found!! =====\n");
                        printf("\n====Investor %d\n", i + 1);
                        printf("Investor's fullName: %s\n", investors[i].fullname);
                        printf("Investor's age: %s\n", investors[i].age);
                        printf("Submitted Identity type: %s\n", investors[i].idtype);
                        printf("Bank Verification Number: %s\n", investors[i].bvn);
                        printf("Investor's Occupation: %s\n", investors[i].Occupa);
                        printf("%s Invested a total of: %c%.2f\n", investors[i].fullname, currency, investors[i].hwmuch);
                        printf("Investement after added interests: %c%.2f\n", currency, investors[i].returninv);
                        printf("Seasons/time: %dyear(s)\n", investors[i].time);
                        foundinv = 1;

                        printf("\nEnter loan amount: ");
                        scanf("%f", &investors[i].loan);

                        printf("\nFor How long: ");
                        scanf("%d", &investors[i].timloan);

                        investors[i].returninv = investors[i].loan +
                                                 (investors[i].loan * 0.10 * investors[i].timloan);

                        printf("Your total repayment for %dyear(s), you are to pay%c%.2f\n", investors[i].timloan, currency, investors[i].returninv);
                    }
                }

                for (int i = 0; i < invcount; i++)
                {
                    if (strcmp(investors[i].bvn, searchbvninv) == 0)
                    {
                        printf("\n========Profile updated =======\n");
                        printf("Investor's fullName: %s\n", investors[i].fullname);
                        printf("Investor's age: %s\n", investors[i].age);
                        printf("Submitted Identity type: %s\n", investors[i].idtype);
                        printf("Bank Verification Number: %s\n", investors[i].bvn);
                        printf("Investor's Occupation: %s\n", investors[i].Occupa);
                        printf("%s Invested a total of: %c%.2f\n", investors[i].fullname, currency, investors[i].hwmuch);
                        printf("\n====== Current loan is %c%.2f", currency, investors[i].loan);
                        printf("Investement after added interests: %c%.2f\n", currency, investors[i].returninv);
                        printf("Seasons/time: %dyear(s)\n", investors[i].time);
                    }
                }
                break;

                // ______________________________________________________________________________
            case 6: // opportunities

                printf("Enter a choice to view our offers\n");
                printf("1. Goat_farm\n");
                printf("2. rent plan\n");
                printf("3. Savings\n");
                printf("4. GoalGetter\n");

                scanf("%d", &choice);
                switch (choice)
                {
                case 1: // GAot farm
                    printf("how much would you like to invest");
                    scanf("%f", &investors[invcount].hwmuch);

                    printf("For our Goat farm plan\n: Duration is 5years\n");
                    printf("Once this done you can get your money back after 5years");
                    printf("How much money would you like to invest Sir/Ma: \n");
                    scanf("%f", &investors[invcount].hwmuch);

                    investors[invcount].returninv = investors[invcount].hwmuch +
                                                    (investors[invcount].hwmuch * 0.15 * 5.0);

                    printf("your Revenue after 5years is %.2f\n", investors[invcount].returninv);
                    break;
                case 2:
                    printf("how much would you like to invest\n");
                    scanf("%f", &investors[invcount].hwmuch);

                    printf(" When is your next Rent Due: \n");
                    scanf("%d", &investors[invcount].time);

                    investors[invcount].returninv = investors[invcount].hwmuch +
                                                    (investors[invcount].hwmuch * 0.15 * investors[invcount].time);
                    printf("your Revenue after %d year(S) is %.2f\n", investors[invcount].time, investors[invcount].returninv);
                    break;
                case 3:
                    printf("how much would you like to Save\n");
                    scanf("%f", &investors[invcount].hwmuch);

                    printf(" Next Due withdrawal: \n");
                    scanf("%d", &investors[invcount].time);

                    investors[invcount].returninv = investors[invcount].hwmuch +
                                                    (investors[invcount].hwmuch * 0.15 * investors[invcount].time);
                    printf("your Revenue after %dyear(S)in savings is: %.2f\n", investors[invcount].time, investors[invcount].returninv);
                    break;
                case 4: // goal getter
                    printf("=======for this plan you cannot without withdraw until your set date=====\n");
                    printf("Read the following before proceeding\n");
                    printf("Enter Y/N\n");
                    scanf("%d", &choice);

                    break;
                default:
                    printf(" wrong input");
                case 7:
                    printf("\nexitting Investment profile................\n");
                }
            }
            break;
        case 3:
            printf("\nExitting  portal............\n");
            break;
        default:
            printf("Wrong input..\n");
            break;
        }

    } while (option != 5);
    return 0;
}
