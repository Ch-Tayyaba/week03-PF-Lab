#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;

int x, y;
const int size = 100;
// these are parallel arrays for all types of users in this application.
string userName[size];
string password[size];
int typeOfUser[size];
string checkUsername;
string checkPassword;
int option;
int userCount = 0;
int y01, y02;

// These are also arrays but only related to Donator.
string donatorName[size];
string donatorCNIC[size];
string donatorDesignation[size];
int donatorMonthlyIncome[size];
int donatorMonthlyExpensis[size];
int donatorCount = -1;
int donationMoney[size];
int donationLimit = 0;
int donationAmount[size][10];
string donationDate[size][10];
int donatorUpdateCount = 0;
int moneyGivenByDonator[size];
bool donationToAdminFlag;
int donations;

// These arrays used to store data for Need Base taker.
string needBaseTakerName[size];
string needBaseTakerCNIC[size];
string needBaseTakerFatherName[size];
string needBaseTakerFatherDesignation[size];
int needBaseTakerMonthlyIncome[size];
int needBaseTakerMonthlyExpensis[size];
string needBaseTakerFeedback[size];
int needBaseAmount[size][10];
string needBaseDate[size][10];
int needBaseTakerCount = -1;
int needBaseTakerUpdateCount = 0;
int needBaseScholarshipLimit = 0;
int needBaseScholarshipCount = 0;

// These arrays for merit base takers.
string meritBaseTakerName[size];
string meritBaseTakerCNIC[size];
string meritBaseTakerDegreeName[size];
int meritBaseTakerTotalMarks[size];
int meritBaseTakerObtMarks[size];
int meritBaseTakerFee[size];
int meritBaseTakerFeedback[size];
int meritBaseAmount[size][10];
string meritBaseDate[size][10];
int meritBaseTakerCount = -1;
int meritBaseTakerUpdateCount = 0;
int meritBaseScholarshipLimit = 0;
int meritBaseScholarshipCount = 0;

// These are just common functions those display some main repeated parts like header. 
void printFrame();
void remainingFrame();
void printSubMenu(string);
int showEnterenceMenu();
void signUpSubMenu();
void inputForSignUp();
void signInSubMenu();
void inputForSignIn();
int adminMenu();
int adminDonatorMenu();
int adminTakerMenu();
int donatorMenu();
int takerMenu();

// These functions for admin interface.
void addDonator();
void RemoveDonator();
void searchDonator();
void viewDonators();
void totalDonations();
void inputDonationAmount();

void addTaker();
void removeTaker();
void viewNeedBaseTakers();
void viewMeritBaseTakers();
int adminTakeroptionMenu();
void searchNeedBaseTaker();
void searchMeritBaseTaker();
void viewNeedBaseTakerFeedBacks();
void viewMeritBaseTakerFeedBacks();

// These all functions for donator information.
void showDonatorPersonalInfoMenu();
void takeDonatorPersonalInfoMenu();
void updateDonatorPersonalInfoMenu();
void viewDonatorOwnPersonalInfo();
int searchInDonatorPersonalInfo();
int toContinueProcess();
void viewEligibilityOfDonator();
int showPaymentMethodForDonation();
bool checkPaymentgivenToAdmin();
void showAccountNumber();
void amountAndDateOfDonation();
int removeDonationRecordMenu();
void removeAllDonationRecord();
void removeSpecficDonationRecord();
int sortOrSearchInDonationRecordMenu();
int sortDonationRecordSubMenu();
void sortDonationRecordByMoneyInAsending();
void sortDonationRecordByMoneyInDesending();
void sortDonationRecordByDateInAsending();
void sortDonationRecordByDateInDesending();
void searchInDonationRecordByMoney();
void searchInDonationRecordByDate();
void viewAllDonationRecords();
void totalDonationMoney();

// These all functions for need base taker information.
void showNeedBaseTakerPersonalInfoMenu();
void takeNeedBaseTakerPersonalInfoMenu();
void updateneedBaseTakerPersonalInfoMenu();
void viewNeedBaseTakerOwnPersonalInfo();
int searchInNeedBaseTakerPersonalInfo();
void viewEligibilityOfNeedBaseTaker();
void amountAndDateOfScholarship01();
void viewAllNeedBaseTakerRecords();
void searchInNeedBaseRecordByMoney();
void searchInNeedBaseRecordByDate();
void needBaseTakerFeedbacks();

// These all functions for merit base taker information and record.
void showMeritBaseTakerPersonalInfoMenu();
void takeMeritBaseTakerPersonalInfoMenu();
void updateMeritBaseTakerPersonalInfoMenu();
int searchInMeritBaseTakerPersonalInfo();
float calculatePercentage();
int calculatePercentageAmountOfFee(float percentage);
void viewMeritBaseTakerOwnPersonalInfo();
void viewEligibilityOfMeritBaseTaker();
void amountAndDateOfScholarship02();
void viewAllMeritBaseTakerRecords();
void searchInMeritBaseRecordByMoney();
void searchInMeritBaseRecordByDate();
void meritBaseTakerFeedbacks();

// These are some validations.
int checkTypeOfUser();
bool isValid(string name);
string nameValidation(string name);

// these all functions are for file handling.
void storeUser();
void loadUser();
void storeDonator();
void loadDonator();
void storeDonations();
void loadDonations();
void storeNeedBaseTaker();
void loadNeedBaseTaker();
void storeNeedBaseScholarships();
void loadNeedBaseScholarships();
void storeMeritBaseTaker();
void loadMeritBaseTaker();
void storeMeritBaseScholarships();
void loadMeritBaseScholarships();
string getfield(string line, int field);

char getCharAtxy(short int x, short int y);
void ShowConsoleCursor(bool showFlag);
void gotoxy(int x, int y);

main()
{
    bool check;
    bool flag = true;
    bool donatorFlag = true;
    char ASCII;
    string subMenu;
    int userType;

    loadUser();
    loadDonator();
    loadDonations();
    loadNeedBaseTaker();
    loadNeedBaseScholarships();
    loadMeritBaseTaker();
    loadMeritBaseScholarships();
    
    ShowConsoleCursor(true);
    while (flag)
    {
        // subMenu = "   Login Screen";
        printFrame();
        printSubMenu(subMenu);
        option = showEnterenceMenu();
        if (option == 2)
        {
            subMenu = "  For Sign Up";
            printFrame();
            printSubMenu(subMenu);
            signUpSubMenu();
            inputForSignUp();
            storeUser();
            Sleep(50);
        }
        else if (option == 1)
        {
            subMenu = "  For Sign In";
            printFrame();
            printSubMenu(subMenu);
            signInSubMenu();
            inputForSignIn();
            storeUser();
            if (checkUsername == "tayyaba_957" && checkPassword == "lubn@957")
            {
                subMenu = "     Admin Menu";
                printFrame();
                printSubMenu(subMenu);
                option = adminMenu();
                if (option == 1)
                {
                    bool adminDonatorFlag = true;
                    while(adminDonatorFlag)
                    {
                        subMenu = "Admin Menu for Donator";
                        printFrame();
                        printSubMenu(subMenu);
                        option = adminDonatorMenu();
                        subMenu = "Admin Menu for Donator";
                        printFrame();
                        printSubMenu(subMenu);
                        if(option == 1)
                        {
                            addDonator();
                            storeUser();
                        }
                        else if(option == 2)
                        {
                            RemoveDonator();
                            storeUser();
                        }
                        else if(option == 3)
                        {
                            viewDonators();
                            getch();
                        }
                        else if(option == 4)
                        {
                            searchDonator();
                        }
                        else if(option == 5)
                        {
                            totalDonations();
                            getch();
                        }
                        else if(option == 6)
                        {
                            inputDonationAmount();
                            storeDonator();
                            getch();
                        }
                        else if(option == 7)
                        {
                            adminDonatorFlag = false;
                        }
                    }
                }
                else if (option == 2)
                {
                    bool adminTakerFlag = true;
                    while(adminTakerFlag)
                    {
                        subMenu = "Admin Menu for Taker";
                        printFrame();
                        printSubMenu(subMenu);
                        subMenu = "Admin Menu for Taker";
                        printFrame();
                        printSubMenu(subMenu);
                        option = adminTakerMenu();
                        if(option == 1)
                        {
                            addTaker();
                            storeUser();
                        }
                        else if (option == 2)
                        {
                            removeTaker();
                            storeUser();
                        }
                        else if (option == 3)
                        {
                            option = adminTakeroptionMenu();
                            if(option == 1)
                            {
                                viewNeedBaseTakers();
                            }
                            else if (option == 2)
                            {
                                viewMeritBaseTakers();
                            }
                        }
                        else if (option == 4)
                        {
                            option = adminTakeroptionMenu();
                            if(option == 1)
                            {
                                searchNeedBaseTaker();
                            }
                            else if (option == 2)
                            {
                                searchMeritBaseTaker();
                            }
                        }
                        else if (option == 5)
                        {
                            option = adminTakeroptionMenu();
                            if(option == 1)
                            {
                                viewNeedBaseTakerFeedBacks();
                            }
                            else if (option == 2)
                            {
                                viewMeritBaseTakerFeedBacks();
                            }
                        }
                        else if (option == 6)
                        {
                            adminTakerFlag = false;
                        }
                    }
                }
                else if (option == 0)
                {
                    Sleep(100);
                }
            }
            userType = checkTypeOfUser();
            if (userType == 1)
            {
                donatorFlag = true;
                while(donatorFlag)
                {
                    subMenu = "     Donator's Menu";
                    printFrame();
                    printSubMenu(subMenu);
                    option = donatorMenu();
                    subMenu = "     Donator's Menu";
                    printFrame();
                    printSubMenu(subMenu);
                    if (option == 1)
                    {
                        if (donatorUpdateCount == 0)
                        {
                            showDonatorPersonalInfoMenu();
                            takeDonatorPersonalInfoMenu();
                            storeDonator();
                        }
                        else
                        {
                            updateDonatorPersonalInfoMenu();
                            storeDonator();
                            option = toContinueProcess();
                            while (option == 1)
                            {
                                subMenu = "     Donator's Menu";
                                printFrame();
                                printSubMenu(subMenu);
                                updateDonatorPersonalInfoMenu();
                                storeDonator();
                                option = toContinueProcess();
                            }
                        }
                    }
                    else if (option == 2)
                    {
                        viewDonatorOwnPersonalInfo();
                        getch();
                    }
                    else if (option == 3)
                    {
                        bool input;
                        input = searchInDonatorPersonalInfo();
                        option = toContinueProcess();
                        while (option == 1 && input)
                        {
                            subMenu = "     Donator's Menu";
                            printFrame();
                            printSubMenu(subMenu);
                            input = searchInDonatorPersonalInfo();
                            option = toContinueProcess();
                        }
                    }
                    else if (option == 4)
                    {
                        viewEligibilityOfDonator();
                        getch(); 
                    }
                    else if (option == 5)
                    {
                        option = showPaymentMethodForDonation();
                        subMenu = "     Donator's Menu";
                        printFrame();
                        printSubMenu(subMenu);
                        if (option == 1)
                        {  
                            checkPaymentgivenToAdmin();
                            if(checkPaymentgivenToAdmin() == true)
                            {
                                amountAndDateOfDonation();
                                storeDonations();
                            }
                            getch();
                        }
                        else if (option == 2)
                        {
                            showAccountNumber();
                            checkPaymentgivenToAdmin();
                            if(checkPaymentgivenToAdmin() == true)
                            {
                                amountAndDateOfDonation();
                                storeDonations();
                            }
                            getch();
                        }
                    }
                    else if (option == 6)
                    {
                        option = removeDonationRecordMenu();
                        if (option == 1)
                        {
                            removeAllDonationRecord();
                            storeDonations();
                        }
                        else if (option == 2)
                        {
                            removeSpecficDonationRecord();
                            storeDonations();
                        }
                    }
                    else if (option == 7)
                    {
                        option = sortOrSearchInDonationRecordMenu();
                        subMenu = "     Donator's Menu";
                        printFrame();
                        printSubMenu(subMenu);
                        if (option == 1)
                        {
                            option = sortDonationRecordSubMenu();
                            subMenu = "     Donator's Menu";
                            printFrame();
                            printSubMenu(subMenu);
                            if (option == 1)
                            {
                                sortDonationRecordByMoneyInAsending();
                            }
                            else if (option == 6)
                            {
                                sortDonationRecordByMoneyInDesending();
                            }
                        }
                        else if (option == 2)
                        {
                            option = sortDonationRecordSubMenu();
                            subMenu = "     Donator's Menu";
                            printFrame();
                            printSubMenu(subMenu);
                            if (option == 1)
                            {
                                sortDonationRecordByDateInAsending();
                            }
                            else if (option == 2)
                            {
                                sortDonationRecordByDateInDesending();
                            }
                        }
                        else if (option == 3)
                        {
                            donatorFlag = false;
                        }
                        
                    }
                    else if (option == 8)
                    {
                        option = sortOrSearchInDonationRecordMenu();
                        subMenu = "     Donator's Menu";
                        printFrame();
                        printSubMenu(subMenu);
                        if (option == 1)
                        {
                            searchInDonationRecordByMoney();
                        }
                        else if (option == 2)
                        {
                            searchInDonationRecordByDate();
                        }
                        
                    }
                    else if (option == 9)
                    {
                        viewAllDonationRecords();
                        getch();
                    }
                    else if (option == 10)
                    {
                        totalDonationMoney();
                        storeDonations();
                        getch();
                    }
                    else if (option == 11 || option == 0)
                    {
                        Sleep(100);
                        donatorFlag = false;
                    }
                }
            }
            if (userType == 2 )
            {
                bool takerFlag01;
                takerFlag01 = true;
                while(takerFlag01)
                {
                    subMenu = "    Need Base Taker's Menu";
                    printFrame();
                    printSubMenu(subMenu);
                    option = takerMenu();
                    subMenu = "     Need Base Taker's Menu";
                    printFrame();
                    printSubMenu(subMenu);
                    if (option == 1)
                    {
                        if (needBaseTakerUpdateCount == 0)
                        {
                            showNeedBaseTakerPersonalInfoMenu();
                            takeNeedBaseTakerPersonalInfoMenu();
                            storeNeedBaseTaker();
                        }
                        else
                        {
                            updateneedBaseTakerPersonalInfoMenu(); 
                            storeNeedBaseTaker();
                            option = toContinueProcess();
                            while (option == 1)
                            {
                                subMenu = "     Need Base Taker's Menu";
                                printFrame();
                                printSubMenu(subMenu);
                                updateneedBaseTakerPersonalInfoMenu(); 
                                storeNeedBaseTaker();
                                option = toContinueProcess();
                            }
                            
                        }
                    
                    }
                    else if (option == 2)
                    {
                        viewNeedBaseTakerOwnPersonalInfo();
                        getch();   
                    }
                    else if (option == 3)
                    {
                        bool input;
                        input = searchInNeedBaseTakerPersonalInfo();
                        option = toContinueProcess();
                        while (option == 1 && input)
                        {
                            subMenu = "     Need Base Taker's Menu";
                            printFrame();
                            printSubMenu(subMenu);
                            input = searchInNeedBaseTakerPersonalInfo();
                            option = toContinueProcess();
                        }  
                    }
                    else if (option == 4)
                    {
                        viewEligibilityOfNeedBaseTaker();
                        getch();
                    }
                    else if (option == 5)
                    {
                        amountAndDateOfScholarship01();
                        storeNeedBaseScholarships();
                        getch();
                    }
                    else if (option == 6)
                    {
                        viewAllNeedBaseTakerRecords();
                        getch();
                    }
                    else if (option == 7)
                    {
                        option = sortOrSearchInDonationRecordMenu();
                        subMenu = "Need Base Taker's Menu";
                        printFrame();
                        printSubMenu(subMenu);   
                        if(option == 1)
                        {
                            searchInNeedBaseRecordByMoney();
                        }
                        else if (option == 2)
                        {
                            searchInNeedBaseRecordByDate();
                        }
                    }
                    else if (option == 8)
                    {
                        needBaseTakerFeedbacks();
                    }
                    else if (option == 9 || option == 0)
                    {
                        Sleep(100);
                        takerFlag01 = false;
                    }
                }
            }
            if (userType == 3 )
            {
                bool takerFlag02;
                takerFlag02 = true;
                while(takerFlag02)
                {
                    subMenu = "Merit Base Taker Menu";
                    printFrame();
                    printSubMenu(subMenu);
                    option = takerMenu();
                    subMenu = "     Merit Base Taker Menu";
                    printFrame();
                    printSubMenu(subMenu);
                    if (option == 1)
                    {
                        
                        if (meritBaseTakerUpdateCount == 0)
                        {
                            showMeritBaseTakerPersonalInfoMenu();
                            takeMeritBaseTakerPersonalInfoMenu();
                            storeMeritBaseTaker();
                        }
                        else
                        {
                            updateMeritBaseTakerPersonalInfoMenu();
                            storeMeritBaseTaker(); 
                            option = toContinueProcess();
                            while (option == 1)
                            {
                                subMenu = "     Merit Base Taker Menu";
                                printFrame();
                                printSubMenu(subMenu);
                                updateMeritBaseTakerPersonalInfoMenu(); 
                                storeMeritBaseTaker();
                                option = toContinueProcess();
                            }
                            
                        }
                    
                    }
                    else if (option == 2)
                    {
                        viewMeritBaseTakerOwnPersonalInfo();
                        getch();   
                    }
                    else if (option == 3)
                    {
                        bool input;
                        input = searchInMeritBaseTakerPersonalInfo();
                        option = toContinueProcess();
                        while (option == 1 && input)
                        {
                            subMenu = "     Merit Base Taker's Menu";
                            printFrame();
                            printSubMenu(subMenu);
                            input = searchInMeritBaseTakerPersonalInfo();
                            option = toContinueProcess();
                        }    
                    }
                    else if (option == 4)
                    {
                        viewEligibilityOfMeritBaseTaker();
                        getch();
                    }
                    else if (option == 5)
                    {
                        amountAndDateOfScholarship02();
                        storeMeritBaseScholarships();
                        getch();
                    }
                    else if (option == 6)
                    {
                        viewAllMeritBaseTakerRecords();
                        getch();
                    }
                    else if (option == 7)
                    {
                        option = sortOrSearchInDonationRecordMenu();
                        subMenu = "Merit Base Taker Menu";
                        printFrame();
                        printSubMenu(subMenu);   
                        if(option == 1)
                        {
                            searchInMeritBaseRecordByMoney();
                        }
                        else if (option == 2)
                        {
                            searchInMeritBaseRecordByDate();
                        }
                    }
                    else if (option == 8)
                    {
                        meritBaseTakerFeedbacks();
                    }
                    else if (option == 9 || option == 0)
                    {
                        Sleep(100);
                        takerFlag02 = false;
                    }
                }
            } 
        } 
    }
}

void printFrame()
{
    system("cls");
    cout << " --------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|**************************************************************************************************************************************************|" << endl;
    cout << "|* ---------------------------------------------------------------------------------------------------------------------------------------------- *|" << endl;
    cout << "|*|                                                                                                                                              |*|" << endl;
    cout << "|*|                                                     SCHOLARSHIP MANAGEMENT SYSTEM                                                            |*|" << endl;
    cout << "|*|                                                                                                                                              |*|" << endl;
    cout << "|* ---------------------------------------------------------------------------------------------------------------------------------------------- *|" << endl;
    cout << "|**************************************************************************************************************************************************|" << endl;
    cout << " -------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
    remainingFrame();
}
void remainingFrame()
{
    x = 0, y = 9;
    gotoxy(x, y);
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|*|                                                                                                                                              |*|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|* ---------------------------------------------------------------------------------------------------------------------------------------------- *|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "|**************************************************************************************************************************************************|" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << " -------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
}
void printSubMenu(string subMenu)
{
    gotoxy(60, 9);
    cout << subMenu << endl;
    gotoxy(57, 10);
    cout << " ----------------------------" << endl;
    gotoxy(57, 11);
    cout << "|****************************|" << endl;
    gotoxy(57, 12);
    cout << " ----------------------------" << endl;
}
int showEnterenceMenu()
{

    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "YOU WANT TO :-";
    gotoxy(x, y);
    y = y + 1;
    cout << "--------------";
    gotoxy(x, y);
    y = y + 1;
    cout << "\t1.Sign In ";
    gotoxy(x, y);
    y = y + 1;
    cout << "\t2.Sign Up ";
    gotoxy(x, y);
    y = y + 1;
    cout << "Enter Option: ";
    cin >> option;
    if (option == 1 || option == 2)
    {
        return option;
    }
    else
    {
        gotoxy(57, 19);
        cout << "Option is not valid.";
    }
    gotoxy(71, 18);
    cout << "       ";
    while ((option != 1 || option != 2))
    {
        gotoxy(71, 18);
        cin >> option;
        if (option == 1 || option == 2)
        {
            return option;
        }
        else
        {
            gotoxy(57, 19);
            cout << "Option is not valid.";
        }
        gotoxy(71, 18);
        cout << "       ";
    }
    return option;
}
void signUpSubMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Enter User Name: " << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Enter Password:" << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Sign up as a :";
    gotoxy(x, y);
    y = y + 1;
    cout << "\t 1. Donator";
    gotoxy(x, y);
    y = y + 1;
    cout << "\t 2. Need Base Taker:";
    gotoxy(x, y);
    y = y + 1;
    cout << "\t 3. Merit Base Taker:";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Enter Option:";
    gotoxy(x, y);
}
void inputForSignUp()
{
    bool check;
    x = 76, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cin >> userName[userCount];
    gotoxy(x, y);
    y = y + 5;
    cin >> password[userCount];
    gotoxy(x, y);
    cin >> typeOfUser[userCount];
    if(typeOfUser[userCount] == 1)
    {
        donatorCount++;
    }
    else if(typeOfUser[userCount] == 2)
    {
        needBaseTakerCount++;
    }
    else if(typeOfUser[userCount] == 3)
    {
        meritBaseTakerCount++;
    }
    userCount++;
}
void signInSubMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Username:";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Password:";
}
void inputForSignIn()
{
    x = 76, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cin >> checkUsername;
    gotoxy(x, y);
    y = y + 1;
    cin >> checkPassword;
}

int adminMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "1.Donator";
    gotoxy(x, y);
    y = y + 1;
    cout << "2.Taker";
    gotoxy(x, y);
    y = y + 1;
    cout << "3.Exit";
    gotoxy(x, y);
    y = y + 1;
    cout << "Enter Option: ";
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    if (option >= 1 && option <= 3)
    {
        return option;
    }
    else
    {
        gotoxy(x, y01);
        cout << "Option is not valid.";
    }
    gotoxy(71, y02);
    cout << "         ";
    int i = 1;
    while (!(option >= 1 && option <= 3) && (i <= 3))
    {
        cin >> option;
        if (option >= 1 && option <= 3)
        {
            return option;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    return 0;
}
int adminDonatorMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "1.Add any donator.";
    gotoxy(x, y);
    y = y + 1;
    cout << "2.Remove any donator.";
    gotoxy(x, y);
    y = y + 1;
    cout << "3.View all donator's record.";
    gotoxy(x, y);
    y = y + 1;
    cout << "4.Search from donator's record.";
    gotoxy(x, y);
    y = y + 1;
    cout << "5.View amount of total donations.";
    gotoxy(x, y);
    y = y + 1;
    cout << "6.Input donation Amount.";
    gotoxy(x, y);
    y = y + 1;
    cout << "7.Exit.";
    gotoxy(x, y);
    y = y + 1;
    cout << "Enter Option: ";
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 7) && (i <= 3))
    {
        cin >> option;
        if (option >= 1 && option <= 7)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    return option;
}
int adminTakerMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "1.Add any Taker.";
    gotoxy(x, y);
    y = y + 1;
    cout << "2.Remove any Taker.";
    gotoxy(x, y);
    y = y + 1;
    cout << "3.View all Taker's record.";
    gotoxy(x, y);
    y = y + 1;
    cout << "4.Search from Taker's record.";
    gotoxy(x, y);
    y = y + 1;
    cout << "5.View feedbacks.";
    gotoxy(x, y);
    y = y + 1;
    cout << "6.Exit." << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "Enter Option: ";
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 6) && (i <= 3))
    {
        cin >> option;
        if (option >= 1 && option <= 6)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    return option;
}

void addDonator()
{
    x = 57, y = 14;
    gotoxy(x, y);
    cout << "=> Enter User Name: " << endl;
    gotoxy(76, y);
    y = y + 1;
    cin >> userName[userCount];
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Enter Password:" << endl;
    gotoxy(76, y);
    y = y + 1;
    cin >> password[userCount];
    typeOfUser[userCount] = 1;
    donatorCount++;
    userCount++;
    gotoxy(x, y);
    cout << "You have successfully add a donator.";
}
void RemoveDonator()
{
    bool flag = false;
    x = 57, y = 14;
    gotoxy(x, y);
    cout << "=> Enter User Name: " << endl;
    gotoxy(76, y);
    y = y + 1;
    cin >> checkUsername;
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Enter Password:" << endl;
    gotoxy(76, y);
    y = y + 1;
    cin >> checkPassword;
    for (int idx = 0; idx < userCount; idx++)
    {
        if (checkUsername == userName[idx] && checkPassword == password[idx] && typeOfUser[idx] == 1)
        {
            userName[idx] = "_";
            password[idx] = "_";
            flag = true;
        }
    }
    if(flag)
    {
        cout << "There is no such donator exist.";
    }
    else
    {
        gotoxy(x, y);
        cout << "You have successfully remove a donator.";
    }
}
void searchDonator()
{
    string CNIC;
    x = 57 , y = 14;
    gotoxy(x,y);
    y = y + 1;
    cout << "Enter CNIC: ";
    gotoxy(76,y);
    cin >> CNIC;
    for (int idx = 0; idx < donatorCount; idx++)
    {
        if(CNIC == donatorCNIC[idx])
        {
            gotoxy(x,y);
            y = y + 1;
            cout << "Name \t CNIC \t Designation \t Income \t Expensis \t Donation Amount";
            cout << donatorName[idx] << donatorCNIC[idx] << donatorDesignation[idx] << donatorMonthlyIncome[idx] << donatorMonthlyExpensis[idx] << donationMoney[idx];
            break;
        }
    }
}
void viewDonators()
{
    x = 57 , y = 14;
    gotoxy(x,y);
    y = y + 1;
    cout << "Name \t CNIC \t Designation \t Income \t Expensis \t Donation Amount";
    for (int idx = 0; idx < donatorCount; idx++)
    {
        if(userName[idx] == "_" && password[idx] == "_")
        {
            continue;
        }
        gotoxy(x,y);
        y = y + 1;
        cout << donatorName[idx] << donatorCNIC[idx] << donatorDesignation[idx] << donatorMonthlyIncome[idx] << donatorMonthlyExpensis[idx] << donationMoney[idx];
    }
}
void totalDonations()
{
    donations = 0;
    for (int idx = 0; idx < donatorCount; idx++)
    {
        donations = donations + donationMoney[idx];
    }
    x = 57 , y = 14;
    gotoxy(x,y);
    y = y + 1;
    cout << "Total Donation Amount is " << donations;
}
void inputDonationAmount()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "Enter UserName: ";
    gotoxy(76, y);
    cin >> checkUsername;
    gotoxy(x, y);
    y = y + 1;
    cout << "Enter Password: ";
    gotoxy(76, y);
    cin >> checkPassword;
    if(checkTypeOfUser() == 1)
    {
        gotoxy(x, y);
        y = y + 1;
        cout << "Enter donation amount: ";
        gotoxy(76, y);
        y = y + 1;
        cin >> moneyGivenByDonator[donatorCount];
        if(donationLimit < 10)
        {
            donationAmount[donatorCount][donationLimit] = moneyGivenByDonator[donatorCount];
        }
        if(donationLimit >= 10)
        {
            donationLimit = 0;
            donationAmount[donatorCount][donationLimit] = moneyGivenByDonator[donatorCount];    
        }
        donationToAdminFlag = true;
    }
    else
    {
        gotoxy(x, y);
        cout << "There is no such donator.";
    }
}

void addTaker()
{
    x = 57, y = 14;
    gotoxy(x, y);
    cout << "=> Enter User Name: " << endl;
    gotoxy(76, y);
    y = y + 1;
    cin >> userName[userCount];
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Enter Password:" << endl;
    gotoxy(76, y);
    cin >> password[userCount];
    gotoxy(x, y);
    y = y + 1;
    cout << "Add: ";
    gotoxy(x, y);
    y = y + 1;
    cout << "1. NeedBase Taker.";
    gotoxy(x, y);
    y = y + 1;
    cout << "2. Merit Base Taker.";
    gotoxy(x, y);
    y = y + 1;
    cout << "Enter Option: ";
    gotoxy(76, y);
    y = y + 1;
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 2))
    {
        cin >> option;
        if (option >= 1 && option <= 2)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    if(option == 1)
    {
        typeOfUser[userCount] = 2;
        needBaseTakerCount++;
    }
    else if(option == 2)
    {
        typeOfUser[userCount] = 3;
        meritBaseTakerCount++;
    }
    userCount++;
    gotoxy(x, y);
    cout << "You have successfully add a taker.";
}
void removeTaker()
{
    bool flag = true;
    int count;
    x = 57, y = 14;
    gotoxy(x, y);
    cout << "=> Enter User Name: " << endl;
    gotoxy(76, y);
    y = y + 1;
    cin >> checkUsername;
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Enter Password:" << endl;
    gotoxy(76, y);
    cin >> checkPassword;
    gotoxy(x, y);
    y = y + 1;
    cout << "Remove: ";
    gotoxy(x, y);
    y = y + 1;
    cout << "1. NeedBase Taker.";
    gotoxy(x, y);
    y = y + 1;
    cout << "2. Merit Base Taker.";
    gotoxy(x, y);
    y = y + 1;
    cout << "Enter Option: ";
    gotoxy(76, y);
    y = y + 1;
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 2) && (i <= 3))
    {
        cin >> option;
        if (option >= 1 && option <= 2)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    if(option == 1)
    {
        for (int idx = 0; idx < needBaseTakerCount; idx++)
        {
            if (checkUsername == userName[idx] && checkPassword == password[idx] && typeOfUser[idx] == 2)
            {
                userName[idx] = "_";
                password[idx] = "_";
                flag = false;
                gotoxy(x, y);
                cout << "You have successfully remove a Taker.";
            }
        }
        if(flag)
        {
            gotoxy(x, y);
            y = y + 1;
            cout << "There is no such Need Base Taker exist.";
        }
    }
    else if(option == 2)
    {
        for (int idx = 0; idx < needBaseTakerCount; idx++)
        {
            if (checkUsername == userName[idx] && checkPassword == password[idx] && typeOfUser[idx] == 3)
            {
                userName[idx] = "_";
                password[idx] = "_";
                flag = false;
                gotoxy(x, y);
                cout << "You have successfully remove a Taker.";
            }
        }
        if(flag)
        {
            gotoxy(x, y);
            y = y + 1;
            cout << "There is no such Merit Base Taker exist.";
        }
    }
}
void viewNeedBaseTakers()
{
    x = 57 , y = 14;
    gotoxy(x,y);
    y = y + 1;
    cout << "Name \t CNIC \t Father Name \t Designation \t Income \t Expensis ";
    for (int idx = 0; idx < needBaseTakerCount; idx++)
    {
        gotoxy(x,y);
        y = y + 1;
        cout << needBaseTakerName[idx] << "\t "<< needBaseTakerCNIC[idx] << "\t" << needBaseTakerFatherName[idx] << "\t " << needBaseTakerFatherDesignation[idx] << "\t " << needBaseTakerMonthlyIncome[idx] << "\t " << needBaseTakerMonthlyExpensis[idx] ;
    }
}
void viewMeritBaseTakers()
{
    x = 57 , y = 14;
    gotoxy(x,y);
    y = y + 1;
    cout << "Name \t CNIC \t Degree Name \t Total Marks \t Obtained Marks \t Total Fee ";
    for (int idx = 0; idx < donatorCount; idx++)
    {
        gotoxy(x,y);
        y = y + 1;
        cout << meritBaseTakerName[idx] << "\t "<< meritBaseTakerCNIC[idx] << "\t" << meritBaseTakerDegreeName[idx] << "\t " << meritBaseTakerTotalMarks[idx] << "\t " << meritBaseTakerObtMarks[idx] << "\t " << meritBaseTakerFee[idx] ;
    }
} 
int adminTakeroptionMenu()
{
    x = 57 , y = 14;
    gotoxy(x,y);
    y = y + 1;
    cout << "1. Need Base Taker.";
    gotoxy(x,y);
    y = y + 1;
    cout << "2. Merit Base Taker.";
    gotoxy(x,y);
    cout << "Enter Option: ";
    gotoxy(76,y);
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 2))
    {
        cin >> option;
        if (option >= 1 && option <= 2)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    return option;
}
void searchNeedBaseTaker()
{
    string CNIC;
    x = 57 , y = 14;
    gotoxy(x,y);
    y = y + 1;
    cout << "Enter CNIC: ";
    cin >> CNIC;
    for (int idx = 0; idx < needBaseTakerCount; idx++)
    {
        if(CNIC == needBaseTakerCNIC[idx])
        {
            gotoxy(x,y);
            y = y + 1;
            cout << needBaseTakerName[idx] << "\t "<< needBaseTakerCNIC[idx] << "\t" << needBaseTakerFatherName[idx] << "\t " << needBaseTakerFatherDesignation[idx] << "\t " << needBaseTakerMonthlyIncome[idx] << "\t " << needBaseTakerMonthlyExpensis[idx] ;
            break;
        }
    }
}
void searchMeritBaseTaker()
{
    string CNIC;
    x = 57 , y = 14;
    gotoxy(x,y);
    y = y + 1;
    cout << "Enter CNIC: ";
    cin >> CNIC;
    for (int idx = 0; idx < meritBaseTakerCount; idx++)
    {
        if(CNIC == meritBaseTakerCNIC[idx])
        {
            gotoxy(x,y);
            y = y + 1;
            cout << meritBaseTakerName[idx] << "\t "<< meritBaseTakerCNIC[idx] << "\t" << meritBaseTakerDegreeName[idx] << "\t " << meritBaseTakerTotalMarks[idx] << "\t " << meritBaseTakerObtMarks[idx] << "\t " << meritBaseTakerFee[idx] ;
            break;
        }
    }
}
void viewNeedBaseTakerFeedBacks()
{
    for (int idx = 0; idx < needBaseTakerCount; idx++)
    {
        cout << idx+1 <<". " << needBaseTakerFeedback[needBaseTakerCount];
    }
    cout << endl;
}
void viewMeritBaseTakerFeedBacks()
{
    for (int idx = 0; idx < meritBaseTakerCount; idx++)
    {
        cout << idx+1 <<". " << meritBaseTakerFeedback[needBaseTakerCount];
    }
    cout << endl;
}

int donatorMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "1.Give/Update your personal information.";
    gotoxy(x, y);
    y = y + 1;
    cout << "2.View your personal information.";
    gotoxy(x, y);
    y = y + 1;
    cout << "3.Search in personal information.";
    gotoxy(x, y);
    y = y + 1;
    cout << "4.View Eligibility.";
    gotoxy(x, y);
    y = y + 1;
    cout << "5.Payment method";
    gotoxy(x, y);
    y = y + 1;
    cout << "6.Remove donation record.";
    gotoxy(x, y);
    y = y + 1;
    cout << "7.Sort donation record.";
    gotoxy(x, y);
    y = y + 1;
    cout << "8.Search in donation record.";
    gotoxy(x, y);
    y = y + 1;
    cout << "9.View your donation record.";
    gotoxy(x, y);
    y = y + 1;
    cout << "10.View how much money you donate.";
    gotoxy(x, y);
    y = y + 1;
    cout << "11.Exit." << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "Enter Option: ";
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 11))
    {
        cin >> option;
        if (option >= 1 && option <= 11)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    return option;
}
void showDonatorPersonalInfoMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Name:";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> CNIC:";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Designation:";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Monthly Income:";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Monthly Expensis:";
}
void takeDonatorPersonalInfoMenu()
{
    x = 76, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cin >> donatorName[donatorCount];
    getch();
    gotoxy(x, y);
    y = y + 1;
    cin >> donatorCNIC[donatorCount];
    gotoxy(x, y);
    y = y + 1;
    cin >> donatorDesignation[donatorCount];
    gotoxy(x, y);
    y = y + 1;
    cin >> donatorMonthlyIncome[donatorCount];
    gotoxy(x, y);
    y = y + 1;
    cin >> donatorMonthlyExpensis[donatorCount];
    donatorUpdateCount++;
}
void updateDonatorPersonalInfoMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y +1;
    cout << "You want to update: ";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 1. Name";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 2. CNIC";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 3. Designation";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 4. Monthly Income";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 5. Monthly Expesis";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 6. All";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 7. Exit";
    gotoxy(x, y);
    y = y +1;
    cout << "Enter Option: ";
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 7))
    {
        cin >> option;
        if (option >= 1 && option <= 7)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    if (option == 1)
    {
        gotoxy(76, y);
        cin >> donatorName[donatorCount];
    }
    else if (option == 2)
    {
        gotoxy(76, y);
        cin >> donatorCNIC[donatorCount];
    }
    else if (option == 3)
    {
        gotoxy(76, y);
        cin >> donatorDesignation[donatorCount];
    }
    else if (option == 4)
    {
        gotoxy(76, y);
        cin >> donatorMonthlyIncome[donatorCount];
    }
    else if (option == 5)
    {
        gotoxy(76, y);
        cin >> donatorMonthlyExpensis[donatorCount];
    }
    else if (option == 6)
    {
        gotoxy(76, y);
        takeDonatorPersonalInfoMenu();
    }
}
void viewDonatorOwnPersonalInfo()
{
    if (donatorUpdateCount == 0)
    {
        x = 57, y = 14;
        gotoxy(x, y);
        y = y + 1;
        cout << "There is no record of Yours.";
    }
    else
    {
        x = 57, y = 14;
        gotoxy(x, y);
        y = y + 1;
        cout << "Name             : " << donatorName[donatorCount];
        gotoxy(x, y);
        y = y + 1;
        cout << "CNIC             : " << donatorCNIC[donatorCount];
        gotoxy(x, y);
        y = y + 1;
        cout << "Designation      : " << donatorDesignation[donatorCount];
        gotoxy(x, y);
        y = y + 1;
        cout << "Monthly Income   : " << donatorMonthlyIncome[donatorCount];
        gotoxy(x, y);
        y = y + 1;
        cout << "Monthly Expensis : " << donatorMonthlyExpensis[donatorCount];
    }
}
int searchInDonatorPersonalInfo()
{
    int option;
    x = 57, y = 14;
    gotoxy(x, y);
    cout << "You want to search your : ";
    gotoxy(x, y);
    y = y +1;
    cout << "You want to update: ";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 1. Name";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 2. CNIC";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 3. Designation";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 4. Monthly Income";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 5. Monthly Expesis";
    gotoxy(x, y);
    y = y + 1;
    cout << "\t=> 6. eXIT";
    gotoxy(x, y);
    y = y + 1;
    cout << "Enter Option:";
    gotoxy(76, y);
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 6))
    {
        cin >> option;
        if (option >= 1 && option <= 6)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    gotoxy(x, y);
    y = y + 1;
    if (option == 1)
    {
        cout << "Your Name is :" << donatorName[donatorCount];
    }
    else if (option == 2)
    {
        cout << "Your CNIC is :" << donatorCNIC[donatorCount];
    }
    else if (option == 3)
    {
        cout << "Your Designation is :" << donatorDesignation[donatorCount];
    }
    else if (option == 4)
    {
        cout << "Your Monthly Income is :" << donatorMonthlyIncome[donatorCount];
    }
    else if (option == 5)
    {
        cout << "Your Monthly Expensis are :" << donatorMonthlyExpensis[donatorCount];
    }
    else if (option == 6)
    {
        return false;
    }
    return true;
}
void viewEligibilityOfDonator()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    if (donatorMonthlyIncome[donatorCount] >= donatorMonthlyExpensis[donatorCount] + 5000)
    {
        cout << "You are Eligible for donation to us. ;-) ";
    }
    else
    {
        cout << "You are not Eligible for donation to us. :-(";
    }
    gotoxy(x,y);
    cout << "Press any key to continue.";
}
int showPaymentMethodForDonation()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "1. Physical method.";
    gotoxy(x, y);
    y = y + 1;
    cout << "2. Online payment method.";
    gotoxy(x, y);
    cout << "Enter option.";
    gotoxy(76, y);
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 2))
    {
        cin >> option;
        if (option >= 1 && option <= 2)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    return option;
}
bool checkPaymentgivenToAdmin()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    if(donationToAdminFlag == true)
    {
        
        cout << "You have successfully gave " << donationAmount[donatorCount][donationLimit] << " money for donation.";
        donationToAdminFlag = false;
        return true;
    }
    else
    {
        cout << "You should meet admin for donation of money.";
        return false;
    }
    return false;
}
void showAccountNumber()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "My account Number is 356121355512 ";
    gotoxy(x, y);
    y = y + 1;
    cout << "You should transfer money to this account number.";
}
void amountAndDateOfDonation()
{
    if (donationLimit < 10 )
    {
        donationAmount[donatorCount][donationLimit] = moneyGivenByDonator[donatorCount];
        x = 57, y = 14;
        gotoxy(x, y);
        y = y + 1;
        cout << "Donation Amount: " << donationAmount[donatorCount][donatorCount];
        gotoxy(x, y);
        y = y + 1;
        cout << "Date: ";
        gotoxy(76, y);
        cin >> donationDate[donatorCount][donatorCount];
        donatorCount++;
    }
    if (donationLimit == 10)
    {
        for (int idx = 0; idx < donationLimit; idx++)
        {
            if ((donationAmount[donatorCount][idx]) == -1 && (donationDate[donatorCount][idx] == "_"))
            {
                donationAmount[donatorCount][idx] = moneyGivenByDonator[donatorCount];
                x = 57, y = 14;
                gotoxy(x, y);
                y = y + 1;
                cout << "Donation Amount: " << donationAmount[donatorCount][idx];
                gotoxy(x, y);
                y = y + 1;
                cout << "Date: ";
                gotoxy(76, y);
                cin >> donationDate[donatorCount][idx];
            }
            else
            {
                x = 57, y = 14;
                gotoxy(x, y);
                y = y + 1;
                cout << "There is no more space for further donation record. You must delete some previous record to store further record.";
            }
        }
    }
}
int removeDonationRecordMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "1. You want to delete all records.";
    gotoxy(x, y);
    cout << "2. You want to delete specfic record.";
    gotoxy(x, y);
    cout << "Enter option:";
    gotoxy(76, y);
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 2))
    {
        cin >> option;
        if (option >= 1 && option <= 2)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    return option;
}
void removeAllDonationRecord()
{
    for (int idx = 0; idx < donationLimit; idx++)
    {
        donationAmount[donatorCount][idx] = -1;
        donationDate[donatorCount][idx] = "_";
    }
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "Your all records are successfully deleted.";
}
void removeSpecficDonationRecord()
{
    bool flag = true;
    string date;
    cin >> date;
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    for (int idx = 0; idx < donationLimit; idx++)
    {
        if (date == donationDate[donatorCount][idx])
        {
            donationAmount[donatorCount][idx] = -1;
            donationDate[donatorCount][idx] = "_";
            gotoxy(x, y);
            cout << "Your record is successfully deleted.";
            flag = false;
            break;
        }
    }
    if (flag)
    {
        gotoxy(x, y);
        cout << "There is no such date in your record";
    }
}
int sortDonationRecordSubMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "1. In Asending order.";
    gotoxy(x, y);
    y = y + 1;
    cout << "2. In Desending order.";
    gotoxy(x, y);
    y = y + 1;
    cout << "Enter Option: ";
    gotoxy(76, y);
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 2))
    {
        cin >> option;
        if (option >= 1 && option <= 2)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    return option;
}
void sortDonationRecordByMoneyInDesending()
{
    int donation;
    for (int i = 0; i < donationLimit - 1; i++)
    {
        for (int j = 1; j < donationLimit; j++)
        {
            if ((donationAmount[donatorCount][i] == -1 ) && (donationDate[donatorCount][i] == "_"))
            {
                if ((donationAmount[donatorCount][j] == -1 ) && (donationDate[donatorCount][j] == "_"))
                {
                    continue;
                }
            }
            if (donationAmount[donatorCount][i] < donationAmount[donatorCount][j])
            {
                donation = donationAmount[donatorCount][i];
                donationAmount[donatorCount][i] = donationAmount[donatorCount][j];
                donationAmount[donatorCount][j] = donation;
            }
        }
    }
}
void sortDonationRecordByMoneyInAsending()
{
    int donation;
    for (int i = 0; i < donationLimit - 1; i++)
    {
        for (int j = 1; j < donationLimit; j++)
        {
            if ((donationAmount[donatorCount][i] == -1 ) && (donationDate[donatorCount][i] == "_"))
            {
                if ((donationAmount[donatorCount][j] == -1 ) && (donationDate[donatorCount][j] == "_"))
                {
                    continue;
                }
            }
            if (donationAmount[donatorCount][i] > donationAmount[donatorCount][j])
            {
                donation = donationAmount[donatorCount][i];
                donationAmount[donatorCount][i] = donationAmount[donatorCount][j];
                donationAmount[donatorCount][j] = donation;
            }
        }
    }
}
void sortDonationRecordByDateInAsending()
{
    string date;
    for (int i = 0; i < donationLimit - 1; i++)
    {
        for (int j = 1; j < donationLimit; j++)
        {
            if ((donationAmount[donatorCount][i] == -1 ) && (donationDate[donatorCount][i] == "_"))
            {
                if ((donationAmount[donatorCount][j] == -1 ) && (donationDate[donatorCount][j] == "_"))
                {
                    continue;
                }
            }
            if (donationDate[donatorCount][i] > donationDate[donatorCount][j])
            {
                date = donationDate[donatorCount][i];
                donationDate[donatorCount][i] = donationDate[donatorCount][j];
                donationDate[donatorCount][i] = date;
            }
        }
    }
}
void sortDonationRecordByDateInDesending()
{
    string date;
    for (int i = 0; i < donationLimit - 1; i++)
    {
        for (int j = 1; j < donationLimit; j++)
        {
            if ((donationAmount[donatorCount][i] == -1 ) && (donationDate[donatorCount][i] == "_"))
            {
                if ((donationAmount[donatorCount][j] == -1 ) && (donationDate[donatorCount][j] == "_"))
                {
                    continue;
                }
            }
            if (donationDate[donatorCount][i] < donationDate[donatorCount][j])
            {
                date = donationDate[donatorCount][i];
                donationDate[donatorCount][i] = donationDate[donatorCount][j];
                donationDate[donatorCount][i] = date;
            }
        }
    }
}
void searchInDonationRecordByMoney()
{
    int donation;
    cout << "=> Enter Donation Money: ";
    cin >> donation;
    for (int idx = 0; idx < donationLimit; idx++)
    {
        if (donationAmount[donatorCount][idx] == -1 && donationDate[donatorCount][idx] == "_")
        {  
            continue;      
        }
        if (donation == donationAmount[donatorCount][idx])
        {
            cout << "Donation \t\t Date" << endl;
            cout << donationAmount[donatorCount][idx] << "\t\t" << donationDate[donatorCount][idx] << endl;
        }
    }
}
void searchInDonationRecordByDate()
{
    string date;
    cout << "=> Enter Donation Date: ";
    cin >> date;
    for (int idx = 0; idx < donationLimit; idx++)
    {
        if (donationAmount[donatorCount][idx] == -1 && donationDate[donatorCount][idx] == "_")
        {
            continue;    
        }
        if (date == donationDate[donatorCount][idx])
        {
            cout << "Donation \t\t Date" << endl;
            cout << donationAmount[donatorCount][idx] << "\t\t" << donationDate[donatorCount][idx] << endl;
        }
    }
}
void viewAllDonationRecords()
{
    for (int idx = 0; idx < donationLimit; idx++)
    {
        if (donationAmount[donatorCount][idx] == -1 && donationDate[donatorCount][idx] == "_")
        {
            continue;
        }
        cout << "Donation \t\t Date" << endl;
        cout << donationAmount[donatorCount][idx] << "\t\t" << donationDate[donatorCount][idx] << endl;
    }
}
void totalDonationMoney()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "You have donated " << donationMoney[donatorCount];
}

int takerMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "1.Update/Give your information.";
    gotoxy(x, y);
    y = y + 1;
    cout << "2.View from your information";
    gotoxy(x, y);
    y = y + 1;
    cout << "3.Search your information.";
    gotoxy(x, y);
    y = y + 1;
    cout << "4.View Eligibility.";
    gotoxy(x, y);
    y = y + 1;
    cout << "5.View how much scholarship you get.";
    gotoxy(x, y);
    y = y + 1;
    cout << "6.View your ouwn schlarship record.";
    gotoxy(x, y);
    y = y + 1;
    cout << "7.Search from your scholaship record.";
    gotoxy(x, y);
    y = y + 1;
    cout << "8.Give feedbacks.";
    gotoxy(x, y);
    y = y + 1;
    cout << "9.Exit." << endl;
    gotoxy(x, y);
    y = y + 1;
    cout << "Enter Option: ";
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 9) && (i <= 3))
    {
        cin >> option;
        if (option >= 1 && option <= 9)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    return option;
}
int sortOrSearchInDonationRecordMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "1. By Donation money.";
    gotoxy(x, y);
    y = y + 1;
    cout << "2. By Donation date.";
    gotoxy(x, y);
    y = y + 1;
    cout << "Enter Option: ";
    gotoxy(76, y);
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 2))
    {
        cin >> option;
        if (option >= 1 && option <= 2)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    return option;
}
int toContinueProcess()
{
    // x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "Press 1 if you want to continue search otherwise press 2 to exit. ";
    gotoxy(x, y);
    cout << "Enter Option: ";
    gotoxy(76, y);
    cin >> option;
    return option;
}

void showNeedBaseTakerPersonalInfoMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Name:";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> CNIC:";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Father Name:";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Father Designation:";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Monthly Income:";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Monthly Expensis:";
}
void takeNeedBaseTakerPersonalInfoMenu()
{
    x = 76, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cin >> needBaseTakerName[needBaseTakerCount];
    gotoxy(x, y);
    y = y + 1;
    cin >> needBaseTakerCNIC[needBaseTakerCount];
    gotoxy(x, y);
    y = y + 1;
    cin >> needBaseTakerFatherName[needBaseTakerCount];
    gotoxy(x, y);
    y = y + 1;
    cin >> needBaseTakerFatherDesignation[needBaseTakerCount];
    gotoxy(x, y);
    y = y + 1;
    cin >> needBaseTakerMonthlyIncome[needBaseTakerCount];
    gotoxy(x, y);
    y = y + 1;
    cin >> needBaseTakerMonthlyExpensis[needBaseTakerCount];
    needBaseTakerUpdateCount++;
}
void updateneedBaseTakerPersonalInfoMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y +1;
    cout << "You want to update: ";
    gotoxy(x, y);
    y = y +1;
    cout << "\t 1. Name";
    gotoxy(x, y);
    y = y +1;
    cout << "\t 2. CNIC";
    gotoxy(x, y);
    y = y +1;
    cout << "\t 3. Father Name";
    gotoxy(x, y);
    y = y +1;
    cout << "\t 4. Designation";
    gotoxy(x, y);
    y = y +1;
    cout << "\t 5. Monthly Income";
    gotoxy(x, y);
    y = y +1;
    cout << "\t 6. Monthly Expesis";
    gotoxy(x, y);
    y = y +1;
    cout << "\t 7. All";
    gotoxy(x, y);
    y = y +1;
    cout << "\t 8. Exit";
    gotoxy(x, y);
    y = y +1;
    cout << "=> Enter Option: ";
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 8))
    {
        cin >> option;
        if (option >= 1 && option <= 8)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    if (option == 1)
    {
        gotoxy(76, y);
        cin >> needBaseTakerName[needBaseTakerCount];
    }
    else if (option == 2)
    {
        gotoxy(76, y);
        cin >> needBaseTakerCNIC[needBaseTakerCount];
    }
    else if (option == 3)
    {
        gotoxy(76, y);
        cin >> needBaseTakerName[needBaseTakerCount];
    }
    else if (option == 4)
    {
        gotoxy(76, y);
        cin >> needBaseTakerFatherDesignation[needBaseTakerCount];
    }
    else if (option == 5)
    {
        gotoxy(76, y);
        cin >> needBaseTakerMonthlyIncome[needBaseTakerCount];
    }
    else if (option == 6)
    {
        gotoxy(76, y);
        cin >> needBaseTakerMonthlyExpensis[needBaseTakerCount];
    }
    else if (option == 7)
    {
        gotoxy(76, y);
        showNeedBaseTakerPersonalInfoMenu();
        takeNeedBaseTakerPersonalInfoMenu();
    }
}
void viewNeedBaseTakerOwnPersonalInfo()
{
    if (needBaseTakerUpdateCount == 0)
    {
        x = 57, y = 14;
        gotoxy(x, y);
        y = y + 1;
        cout << "There is no record of Yours.";
    }
    else
    {
        x = 57, y = 14;
        gotoxy(x, y);
        y = y + 1;
        cout << "Name             : " << needBaseTakerName[needBaseTakerCount];
        gotoxy(x, y);
        y = y + 1;
        cout << "CNIC             : " << needBaseTakerCNIC[needBaseTakerCount];
        gotoxy(x, y);
        y = y + 1;
        cout << "Name             : " << needBaseTakerFatherName[needBaseTakerCount];
        gotoxy(x, y);
        y = y + 1;
        cout << "Designation      : " << needBaseTakerFatherDesignation[needBaseTakerCount];
        gotoxy(x, y);
        y = y + 1;
        cout << "Monthly Income   : " << needBaseTakerMonthlyIncome[needBaseTakerCount];
        gotoxy(x, y);
        y = y + 1;
        cout << "Monthly Expensis : " << needBaseTakerMonthlyExpensis[needBaseTakerCount];
    }
}
int searchInNeedBaseTakerPersonalInfo()
{
    int option;
    x = 57, y = 14;
    gotoxy(x, y);
    cout << "You want to search your : ";
    gotoxy(x, y);
    y = y +1;
    cout << "You want to update: ";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 1. Name";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 2. CNIC";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 3. Father Name";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 4. Father Designatin: ";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 5. Monthly Income";
    gotoxy(x, y);
    y = y +1;
    cout << "\t=> 6. Monthly Expensis";
    gotoxy(x, y);
    y = y + 1;
    cout << "\t=> 7. Exit";
    gotoxy(x, y);
    y = y + 1;
    cout << "Enter Option:";
    gotoxy(76, y);
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 7))
    {
        cin >> option;
        if (option >= 1 && option <= 7)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    gotoxy(x, y);
    y = y + 1;
    if (option == 1)
    {
        cout << "Your Name is :" << needBaseTakerName[needBaseTakerCount];
    }
    else if (option == 2)
    {
        cout << "Your CNIC is :" << needBaseTakerCNIC[needBaseTakerCount];
    }
    else if (option == 3)
    {
        cout << "Your Father Name is :" << needBaseTakerFatherName[needBaseTakerCount];
    }
    else if (option == 4)
    {
        cout << "Your Father Designation is :" << needBaseTakerFatherDesignation[needBaseTakerCount];
    }
    else if (option == 5)
    {
        cout << "Your Monthly Income is :" << needBaseTakerMonthlyIncome[needBaseTakerCount];
    }
    else if (option == 6)
    {
        cout << "Your Monthly Expensis are :" << needBaseTakerMonthlyExpensis[needBaseTakerCount];
    }
    else if (option == 7)
    {
        return false;
    }
    return true;
}
void viewEligibilityOfNeedBaseTaker()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    if (needBaseTakerMonthlyIncome[needBaseTakerCount] <= needBaseTakerMonthlyExpensis[needBaseTakerCount] + 5000)
    {
        cout << "You are Eligible for ScholarShip. ;-) ";
    }
    else
    {
        cout << "You are not Eligible for ScholarShip :-(";
    }
    gotoxy(x,y);
}
void amountAndDateOfScholarship01()
{
    int scholarship;

    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    if (needBaseTakerMonthlyIncome[needBaseTakerCount] <=  (needBaseTakerMonthlyExpensis[needBaseTakerCount]))
    {
        scholarship = 50000;
    }
    else if (needBaseTakerMonthlyIncome[needBaseTakerCount] <= (needBaseTakerMonthlyExpensis[needBaseTakerCount] + 10000))
    {
        scholarship = 30000;
    }
    else
    {
        scholarship = 0;
    }
    if(needBaseScholarshipLimit < 10)
    {
        needBaseAmount[needBaseScholarshipCount][needBaseScholarshipLimit] = scholarship;
    }
    if (needBaseScholarshipLimit >= 10)
    {
        needBaseScholarshipLimit = 0;
        needBaseAmount[needBaseScholarshipCount][needBaseScholarshipLimit] = scholarship;
    }
    cout << "Your ScholarShip is :" << scholarship ;
    cout << "Enter Date: ";
    cin >> needBaseDate[needBaseScholarshipCount][needBaseScholarshipLimit];
}
void viewAllNeedBaseTakerRecords()
{
    for (int idx = 0; idx < needBaseScholarshipLimit; idx++)
    {
        cout << "Scholarship \t\t Date" << endl;
        cout << needBaseAmount[needBaseTakerCount][idx] << "\t\t" << needBaseDate[needBaseTakerCount][idx] << endl;
    }
}
void searchInNeedBaseRecordByMoney()
{
    int scholarship;
    cout << "=> Enter Donation Money: ";
    cin >> scholarship;
    for (int idx = 0; idx < needBaseScholarshipLimit; idx++)
    {
        if (scholarship == needBaseAmount[][idx])
        {
            cout << "needBase \t\t Date" << endl;
            cout << needBaseAmount[needBaseTakerCount][idx] << "\t\t" << needBaseDate[needBaseTakerCount][idx] << endl;
        }
    }
}
void searchInNeedBaseRecordByDate()
{
    string date;
    cout << "=> Enter needBase Date: ";
    cin >> date;
    for (int idx = 0; idx < needBaseScholarshipLimit; idx++)
    {
        if (date == needBaseDate[needBaseTakerCount][idx])
        {
            cout << "needBase \t\t Date" << endl;
            cout << needBaseAmount[needBaseTakerCount][idx] << "\t\t" << needBaseDate[needBaseTakerCount][idx] << endl;
        }
    }
}
void needBaseTakerFeedbacks()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "Give Your FeedBack: ";
    gotoxy(76, y);
    y = y + 1;
    cin >> needBaseTakerFeedback[needBaseTakerCount];
    gotoxy(x, y);
    cout << "Thanks for your feedback.";
}

void showMeritBaseTakerPersonalInfoMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Name:";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> CNIC:";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Dgree Name:";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Total Marks:";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Obtained Marks";
    gotoxy(x, y);
    y = y + 1;
    cout << "=> Total Fee:";
}
void takeMeritBaseTakerPersonalInfoMenu()
{
    x = 76, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cin >> meritBaseTakerName[meritBaseTakerCount];
    gotoxy(x, y);
    y = y + 1;
    cin >> meritBaseTakerCNIC[meritBaseTakerCount];
    gotoxy(x, y);
    y = y + 1;
    cin >> meritBaseTakerDegreeName[meritBaseTakerCount];
    gotoxy(x, y);
    y = y + 1;
    cin >> meritBaseTakerTotalMarks[meritBaseTakerCount];
    gotoxy(x, y);
    y = y + 1;
    cin >> meritBaseTakerObtMarks[meritBaseTakerCount];
    gotoxy(x, y);
    y = y + 1;
    cin >> meritBaseTakerFee[meritBaseTakerCount];
    meritBaseTakerUpdateCount++;
}
void updateMeritBaseTakerPersonalInfoMenu()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y +1;
    cout << "You want to update: ";
    gotoxy(x, y);
    y = y +1;
    cout << "\t 1. Name";
    gotoxy(x, y);
    y = y +1;
    cout << "\t 2. CNIC";
    gotoxy(x, y);
    y = y +1;
    cout << "\t3. Dgree Name:";
    gotoxy(x, y);
    y = y + 1;
    cout << "\t4. Total Marks:";
    gotoxy(x, y);
    y = y + 1;
    cout << "\t5. Obtained Marks";
    gotoxy(x, y);
    y = y + 1;
    cout << "\t6. Total Fee:";
    gotoxy(x, y);
    y = y +1;
    cout << "\t 7. All";
    gotoxy(x, y);
    y = y +1;
    cout << "\t 8. Exit";
    gotoxy(x, y);
    y = y +1;
    cout << "=> Enter Option: ";
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 8))
    {
        cin >> option;
        if (option >= 1 && option <= 8)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }
    if (option == 1)
    {
        gotoxy(76, y);
        cin >> meritBaseTakerName[meritBaseTakerCount];
    }
    else if (option == 2)
    {
        gotoxy(76, y);
        cin >> meritBaseTakerCNIC[meritBaseTakerCount];
    }
    else if (option == 3)
    {
        gotoxy(76, y);
        cin >> meritBaseTakerDegreeName[meritBaseTakerCount];
    }
    else if (option == 4)
    {
        gotoxy(76, y);
        cin >> meritBaseTakerTotalMarks[meritBaseTakerCount];
    }
    else if (option == 5)
    {
        gotoxy(76, y);
        cin >> meritBaseTakerObtMarks[meritBaseTakerCount];
    }
    else if (option == 6)
    {
        gotoxy(76, y);
        cin >> meritBaseTakerFee[meritBaseTakerCount];
    }
    else if (option == 7)
    {
        gotoxy(76, y);
        showMeritBaseTakerPersonalInfoMenu();
        takeMeritBaseTakerPersonalInfoMenu();
    }
}
void viewMeritBaseTakerOwnPersonalInfo()
{
    if (meritBaseTakerUpdateCount == 0)
    {
        x = 57, y = 14;
        gotoxy(x, y);
        y = y + 1;
        cout << "There is no record of Yours.";
    }
    else
    {
        x = 57, y = 14;
        gotoxy(x, y);
        y = y + 1;
        cout << "Name             : " << meritBaseTakerName[meritBaseTakerCount];
        gotoxy(x, y);
        y = y + 1;
        cout << "CNIC             : " << meritBaseTakerCNIC[meritBaseTakerCount];
        gotoxy(x, y);
        y = y + 1;
        cout << "Degree Name      : " << meritBaseTakerDegreeName[meritBaseTakerCount];
        gotoxy(x, y);
        y = y + 1;
        cout << "Total Marks      : " << meritBaseTakerTotalMarks[meritBaseTakerCount];
        gotoxy(x, y);
        y = y + 1;
        cout << "Obtained Marks   : " << meritBaseTakerObtMarks[meritBaseTakerCount];
        gotoxy(x, y);
        y = y + 1;
        cout << "Total Fee        : " << meritBaseTakerFee[meritBaseTakerCount];
    }
}
int searchInMeritBaseTakerPersonalInfo()
{
    int option;
    x = 57, y = 14;
    gotoxy(x, y);
    cout << "You want to search your : ";
    gotoxy(x, y);
    y = y +1;
    cout << "You want to update: ";
    gotoxy(x, y);
    y = y +1;
    cout << "\t 1. Name";
    gotoxy(x, y);
    y = y +1;
    cout << "\t 2. CNIC";
    gotoxy(x, y);
    y = y +1;
    cout << "\t 3. Dgree Name:";
    gotoxy(x, y);
    y = y + 1;
    cout << "\t4. Total Marks:";
    gotoxy(x, y);
    y = y + 1;
    cout << "\t5. Obtained Marks";
    gotoxy(x, y);
    y = y + 1;
    cout << "\t6. Total Fee:";
    gotoxy(x, y);
    y = y +1;
    cout << "\t7. Exit";
    gotoxy(x, y);
    y = y +1;
    cout << "=> Enter Option: ";
    gotoxy(76, y);
    cin >> option;
    gotoxy(x, y);
    y01 = y + 1;
    y02 = y - 1;
    int i = 1;
    while (!(option >= 1 && option <= 7))
    {
        cin >> option;
        if (option >= 1 && option <= 7)
        {
            break;
        }
        else
        {
            gotoxy(x, y01);
            cout << "Option is not valid.";
        }
        gotoxy(71, y02);
        cout << "         ";
        i++;
    }   
    gotoxy(x, y);
    y = y + 1;
    if (option == 1)
    {
        cout << "Your Name is :" << needBaseTakerName[needBaseTakerCount];
    }
    else if (option == 2)
    {
        cout << "Your CNIC is :" << needBaseTakerCNIC[needBaseTakerCount];
    }
    else if (option == 3)
    {
        cout << "Your Degree Name is :" << needBaseTakerFatherName[needBaseTakerCount];
    }
    else if (option == 4)
    {
        cout << "Your Total Marks are :" << needBaseTakerFatherDesignation[needBaseTakerCount];
    }
    else if (option == 5)
    {
        cout << "Your Obtained Marks :" << needBaseTakerMonthlyIncome[needBaseTakerCount];
    }
    else if (option == 6)
    {
        cout << "Your Total Fee :" << needBaseTakerMonthlyExpensis[needBaseTakerCount];
    }
    else if (option == 7)
    {
        return false;
    }
    return true;
}
float calculatePercentage()
{
    return  (meritBaseTakerObtMarks[meritBaseTakerCount] * 100) / meritBaseTakerTotalMarks[meritBaseTakerCount];
}
int calculatePercentageAmountOfFee(float percentage)
{
    return (percentage/100) * meritBaseTakerFee[meritBaseTakerCount];
}
void viewEligibilityOfMeritBaseTaker()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    if (meritBaseTakerObtMarks[meritBaseTakerCount] >= 0.5 * (meritBaseTakerTotalMarks[meritBaseTakerCount]))
    {
        cout << "You are Eligible for ScholarShip. ;-) ";
    }
    else
    {
        cout << "You are not Eligible for ScholarShip :-(";
    }
    gotoxy(x,y);
}
void amountAndDateOfScholarship02()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    float percentage = calculatePercentage();
    int scholarship;
    if (percentage >= 90)
    {
        scholarship = calculatePercentageAmountOfFee(90);
    }
    else if (percentage >= 80)
    {
        scholarship = calculatePercentageAmountOfFee(80);
    }
    else if (percentage >= 70)
    {
        scholarship = calculatePercentageAmountOfFee(70);
    }
    else if (percentage >= 60)
    {
        scholarship = calculatePercentageAmountOfFee(60);
    }
    else if (percentage >= 50)
    {
        scholarship = calculatePercentageAmountOfFee(50);
    }
    if(meritBaseScholarshipLimit < 10)
    {
    meritBaseAmount[meritBaseScholarshipCount][meritBaseScholarshipLimit] = scholarship;
    }
    if (meritBaseScholarshipLimit >= 10)
    {
        meritBaseScholarshipLimit = 0;
        meritBaseAmount[meritBaseScholarshipCount][meritBaseScholarshipLimit] = scholarship;
    }
    cout << "Your ScholarShip is :" << scholarship ;
    cout << "Enter Date: ";
    cin >> meritBaseDate[meritBaseScholarshipCount][meritBaseScholarshipLimit];

}
void viewAllMeritBaseTakerRecords()
{
    for (int idx = 0; idx < meritBaseScholarshipLimit; idx++)
    {
        cout << "Scholarship \t\t Date" << endl;
        cout << meritBaseAmount[meritBaseTakerCount][idx] << "\t\t" << meritBaseDate[donatorCount][idx] << endl;
    }
}
void searchInMeritBaseRecordByMoney()
{
    int scholarship;
    cout << "=> Enter Donation Money: ";
    cin >> scholarship;
    for (int idx = 0; idx < meritBaseScholarshipLimit; idx++)
    {
        if (scholarship == meritBaseAmount[meritBaseTakerCount][idx])
        {
            cout << "meritBase \t\t Date" << endl;
            cout << meritBaseAmount[meritBaseTakerCount][idx] << "\t\t" << meritBaseDate[meritBaseTakerCount][idx] << endl;
        }
    }
}
void searchInMeritBaseRecordByDate()
{
    string date;
    cout << "=> Enter meritBase Date: ";
    cin >> date;
    for (int idx = 0; idx < meritBaseScholarshipLimit; idx++)
    {
        if (date == meritBaseDate[meritBaseTakerCount][idx])
        {
            cout << "meritBase \t\t Date" << endl;
            cout << meritBaseAmount[meritBaseTakerCount][idx] << "\t\t" << meritBaseDate[meritBaseTakerCount][idx] << endl;
        }
    }
}
void meritBaseTakerFeedbacks()
{
    x = 57, y = 14;
    gotoxy(x, y);
    y = y + 1;
    cout << "Give Your FeedBack: ";
    gotoxy(76, y);
    y = y + 1;
    cin >> meritBaseTakerFeedback[meritBaseTakerCount];
    gotoxy(x, y);
    cout << "Thanks for your feedback.";
} 

int checkTypeOfUser()
{
    for (int idx = 1; idx <= 3; idx++)
    {
        for (int idx = 0; idx < userCount; idx++)
        {
            if (checkUsername == userName[idx] && checkPassword == password[idx])
            {
                return typeOfUser[idx];
                break;
            }
            cout << "Try Again";
        }
    }
    return 0;
}
bool isValid(string name)
{
    bool flag = true;
    for(int idx = 0; idx < userCount; idx++)
    {
        if(userName[idx] == checkUsername)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
string nameValidation(string name)
{
    bool flag = true;
    while(flag)
    {
        for(int idx = 0; idx < name.length() ; idx++)
        {
            if(!((name[idx] >= 97 && name[idx] <= 122) && (name[idx] >= 65 && name[idx] <= 90) && (name[idx] >= 48 && name[idx] <= 59) && (name[idx] >= 33 && name[idx] <= 42)))
            {
                cout << "Invalid" << endl;
                cin >> name;
                break;
            }
            else
            {
                flag = false;
            }
        }
    }
    return name;
}

void storeUser()
{
    fstream file;
    file.open("usersInfo.txt", ios :: out);
    int idx = 0;
    while(idx < userCount)
    {
        file << userName[idx] << ",";
        file << password[idx] << ",";
        file << typeOfUser[idx] << endl;
        idx++;
    }
    file.close();
}
void loadUser()
{
    string line;
    fstream file;
    file.open("usersInfo.txt", ios :: in);
    while(getline(file,line))
    {
        userName[userCount] = getfield(line,1);       
        password[userCount] = getfield(line,2); 
        typeOfUser[userCount] = stoi(getfield(line,3)); 
        userCount++;
    }
    file.close();
}
void storeDonations()
{
    fstream file;
    file.open("donationsRecord.txt", ios :: out);
    int idx01 = 0;
    while(idx01 < donatorCount)
    {
        int idx02 = 0;
        while(idx02 < donationLimit)
        {
            file << donationAmount[idx01][idx02] << ",";
            file << donationDate[idx01][idx02] << endl ;
            idx02++;
        }
        idx01++;
    }
    file.close();
}
void loadDonations()
{
    string line;
    fstream file;
    file.open("donationsRecord.txt", ios :: in);
    while(getline(file,line))
    {
        donationAmount[donatorCount][donationLimit] = stoi(getfield(line,1));
        donationDate[donatorCount][donationLimit] = getfield(line, 2);
        donationLimit++;
    }
    file.close();
}
void storeDonator()
{
    fstream file;
    file.open("donatorInfo.txt", ios :: out);
    int idx = 0;
    while(idx < donatorCount)
    {
        file << donatorName[idx] << ",";
        file << donatorCNIC[idx] << ",";
        file << donatorDesignation[idx] << ",";
        file << donatorMonthlyIncome[idx] << ",";
        file << donatorMonthlyExpensis[idx] << ",";
        file << donationMoney[idx] << ",";
        file << moneyGivenByDonator[idx] << endl;
        idx++;
    }
    file.close();
}
void loadDonator()
{
    string line;
    fstream file;
    file.open("donatorInfo.txt", ios :: in);
    while(getline(file,line))
    {
        donatorName[donatorCount] = getfield(line,1);       
        donatorCNIC[donatorCount] = getfield(line,2); 
        donatorDesignation[donatorCount] = getfield(line,3);
        donatorMonthlyIncome[donatorCount] = stoi(getfield(line,4));
        donatorMonthlyExpensis[donatorCount] = stoi(getfield(line,5));
        donationMoney[donatorCount] = stoi(getfield(line,6));
        moneyGivenByDonator[donatorCount] = stoi(getfield(line,7)); 
        donatorCount++;
    }
    file.close();
} 
void storeNeedBaseTaker()
{
    fstream file;
    file.open("needBaseTakerInfo.txt", ios :: out);
    int idx = 0;
    while(idx < needBaseTakerCount + 1)
    {
        file << needBaseTakerName[idx] << ",";
        file << needBaseTakerCNIC[idx] << ",";
        file << needBaseTakerFatherName[idx] << ",";
        file << needBaseTakerFatherDesignation[idx] << ",";
        file << needBaseTakerMonthlyIncome[idx] << ",";
        file << needBaseTakerMonthlyExpensis[idx] << ",";
        file << needBaseTakerFeedback[idx] << endl;
        idx++;
    }
    file.close();
}
void loadNeedBaseTaker()
{
    string line;
    fstream file;
    file.open("needBaseTakerInfo.txt", ios :: in);
    while(getline(file,line))
    {
        needBaseTakerName[needBaseTakerCount] = getfield(line,1);       
        needBaseTakerCNIC[needBaseTakerCount] = getfield(line,2); 
        needBaseTakerFatherName[needBaseTakerCount] = getfield(line,3);
        needBaseTakerFatherDesignation[needBaseTakerCount] = getfield(line,4);
        needBaseTakerMonthlyIncome[needBaseTakerCount] = stoi(getfield(line,5));
        needBaseTakerMonthlyExpensis[needBaseTakerCount] = stoi(getfield(line,6));
        needBaseTakerFeedback[needBaseTakerCount] = getfield(line,7); 
        needBaseTakerCount++;
    }
    file.close();
}
void storeNeedBaseScholarships()
{
    fstream file;
    file.open("NBacholarshipRecord.txt", ios :: out);
    int idx01 = 0;
    while(idx01 < needBaseTakerCount)
    {
        int idx02 = 0;
        while(idx02 < needBaseScholarshipLimit)
        {
            file << needBaseAmount[idx01][idx02] << ",";
            file << needBaseDate[idx01][idx02] << endl ;
            idx02++;
        }
        idx01++;
    }
    file.close();
}
void loadNeedBaseScholarships()
{
    string line;
    fstream file;
    file.open("NBacholarshipRecord.txt", ios :: in);
    while(getline(file,line))
    {
        donationAmount[needBaseTakerCount][needBaseScholarshipLimit] = stoi(getfield(line,1));
        donationDate[needBaseTakerCount][needBaseScholarshipLimit] = getfield(line, 2);
        needBaseScholarshipLimit++;
    }
    file.close();
}
void storeMeritBaseTaker()
{
    fstream file;
    file.open("meritBaseTakerInfo.txt", ios :: out);
    int idx = 0;
    while(idx < meritBaseTakerCount + 1)
    {
        file << meritBaseTakerName[idx] << ",";
        file << meritBaseTakerCNIC[idx] << ",";
        file << meritBaseTakerDegreeName[idx] << ",";
        file << meritBaseTakerTotalMarks[idx] << ",";
        file << meritBaseTakerObtMarks[idx] << ",";
        file << meritBaseTakerFee[idx] << ",";
        file << meritBaseTakerFeedback[idx] << endl;
        idx++;
    }
    file.close();
}
void loadMeritBaseTaker()
{
    string line;
    fstream file;
    file.open("meritBaseTakerInfo.txt", ios :: in);
    while(getline(file,line))
    {
        meritBaseTakerName[meritBaseTakerCount] = getfield(line,1);       
        meritBaseTakerCNIC[meritBaseTakerCount] = getfield(line,2); 
        meritBaseTakerDegreeName[meritBaseTakerCount] = getfield(line,3);
        meritBaseTakerTotalMarks[meritBaseTakerCount] = stoi(getfield(line,4));
        meritBaseTakerObtMarks[meritBaseTakerCount] = stoi(getfield(line,5));
        meritBaseTakerFee[meritBaseTakerCount] = stoi(getfield(line,6));
        meritBaseTakerFeedback[meritBaseTakerCount] = stoi(getfield(line,7)); 
        meritBaseTakerCount++;
    }
    file.close();
}
void storeMeritBaseScholarships()
{
    fstream file;
    file.open("MBscholarshipRecord.txt", ios :: out);
    int idx01 = 0;
    while(idx01 < meritBaseTakerCount)
    {
        int idx02 = 0;
        while(idx02 < meritBaseScholarshipLimit)
        {
            file << meritBaseAmount[idx01][idx02] << ",";
            file << meritBaseDate[idx01][idx02] << endl ;
            idx02++;
        }
        idx01++;
    }
    file.close();
}
void loadMeritBaseScholarships()
{
    string line;
    fstream file;
    file.open("MBscholarshipRecord.txt", ios :: in);
    while(getline(file,line))
    {
        donationAmount[meritBaseTakerCount][meritBaseScholarshipLimit] = stoi(getfield(line,1));
        donationDate[meritBaseTakerCount][meritBaseScholarshipLimit] = getfield(line, 2);
        meritBaseScholarshipLimit++;
    }
    file.close();
}
string getfield(string line, int field)
{
    int commaCount = 1;
    string item = "";
    for(int idx = 0; idx < line.length(); idx++)
    {
        if(line[idx] == ',')
        {
            commaCount++;
        }
        else if(commaCount == field)
        {
            item = item + line[idx];
        }
    }
    return item;
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
