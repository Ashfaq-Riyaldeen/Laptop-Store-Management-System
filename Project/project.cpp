//USERNAME:grp68
//PASSWORD:admin


#include <iostream>
#include "Laptop.h"
#include "SLL.h"
#include <cstddef>
#include <stdlib.h>
#include "Queue_History.h"
#include <fstream>
#include <string>

using namespace std;

//------------------------------------------------------------------------------------------------------------------------------------------------
string setLaptopBrand(int Nmodel);
string setLaptopRam(int Nram);
string setLaptopProcessor(int Nprocessor);
int setLaptopQuantity(int Nquantity);
int setLaptopPrice(int Nprice);
void addLaptop();
//------------------------------------------------------------------------------------------------------------------------------------------------
void updateSoldout();
int histoyOption(int option);
void soldoutHistory();
//------------------------------------------------------------------------------------------------------------------------------------------------
void sortLaptop();
//------------------------------------------------------------------------------------------------------------------------------------------------
void login();
void forgot();
void adminPannal();
//------------------------------------------------------------------------------------------------------------------------------------------------
Single_liked_list invetoryList;
Single_liked_list soldoutHistoryAll;
Queue_History soldoutHistoryLast20;

int main()
{
    do {
        system("color 0A");
        cout << "\n\t\t\t===============================================================" << endl;
        cout << "\t\t\t\t\t     WELCOME TO LAPTOP STORE\n";
        cout << "\t\t\t===============================================================\n" << endl;

        cout << "\t\t\t\t\t1 - Login\n";
        cout << "\t\t\t\t\t2 - Forgot Password\n";
        cout << "\t\t\t\t\t3 - Exit\n\n";
        cout << "\t\t\t\t\tEnter Your Choice: ";
        int option;
        cin >> option;

        switch (option)
        {
        case 1:
            login();
            break;
        case 2:
            forgot();
            break;
        case 3:
            system("cls");
            return 0;
        default:
            cout << "\n\t\t\t\t\tYour input is wrong\n";
            {cout << "\n\t\t\t\t\tPress Enter to exit...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }
            break;
        }

    } while (true);

};

//------------------------------------------------------------------------------------------------------------------------------------------------
string setLaptopBrand(int Nmodel) {
    switch (Nmodel)
    {
    case 1:
        return "MSI   ";
    case 2:
        return "DELL  ";
    case 3:
        return "HP    ";
    case 4:
        return "ASUS  ";
    case 5:
        return "LENOVO";
    default:
        cout << "\n\t\t\tInvalid Option, Enter the Correct Option: ";
        int reEnteredModel;
        cin >> reEnteredModel;
        return setLaptopBrand(reEnteredModel);
    }
}

string setLaptopRam(int Nram) {

    switch (Nram)
    {
    case 1:
        return " 4GB";
    case 2:
        return " 8GB";
    case 3:
        return "16GB";
    case 4:
        return "32GB";

    default:
        cout << "\n\t\t\tInvalid Option, Enter the Correct Option: ";
        int reEnteredRam;
        cin >> reEnteredRam;
        return setLaptopRam(reEnteredRam);
    }
}

string setLaptopProcessor(int Nprocessor) {

    switch (Nprocessor)
    {
    case 1:
        return "i3";
    case 2:
        return "i5";
    case 3:
        return "i7";
    
    default:
        cout << "\n\t\t\tInvalid Option, Enter the Correct Option: ";
        int reEnteredProcessor;
        cin >> reEnteredProcessor;
        return setLaptopProcessor(reEnteredProcessor);
    }
}

int setLaptopQuantity(int Nquantity) {
    if (Nquantity >= 0) {
        return Nquantity;
    }
    else {
        cout << "\n\t\t\tInvalid Quantity, Enter the Correct Quantity: ";
        int reEnteredQuantity;
        cin >> reEnteredQuantity;
        return setLaptopQuantity(reEnteredQuantity);
    }
}

int setLaptopPrice(int Nprice) {
    if (Nprice >= 0) {
        return Nprice;
    }
    else {
        cout << "\n\t\t\tInvalid Price, Enter the Correct Price: ";
        int reEnteredPrice;
        cin >> reEnteredPrice;
        return setLaptopPrice(reEnteredPrice);
    }
}

void addLaptop() {

    Laptop* temp = new Laptop();

    cout << "\t\t\t1 - MSI  | 2 - DELL  | 3 - HP  | 4 - ASUS  | 5 - LENOVO \n";
    cout << "\t\t\tEnter the Laptop Brand Number : ";
    int model;
    cin >> model;
    temp->Brand = setLaptopBrand(model);

    cout << "\n\t\t\t1 - 4GB   | 2 - 8GB  | 3 - 16GB  | 4 - 32GB\n";
    cout << "\t\t\tEnter the Laptop RAM Number : ";
    int ram;
    cin >> ram;
    temp->RAM = setLaptopRam(ram);

    cout << "\n\t\t\t1 - i3   | 2 - i5  | 3 - i7 \n";
    cout << "\t\t\tEnter the Laptop Processor Number : ";
    int processor;
    cin >> processor;
    temp->Processor = setLaptopProcessor(processor);
    cout << "\n";

    cout << "\t\t\tEnter the Laptop Quantity :";
    int quantity;
    cin >> quantity;
    temp->Quantity = setLaptopQuantity(quantity);
    cout << "\n";

    cout << "\t\t\tEnter the Laptop Price : ";
    int price;
    cin >> price;
    temp->Price = setLaptopPrice(price);

    invetoryList.insertLaptop(temp);

    cout << "\n\t\t\t============================================" << endl;
    cout << "\t\t\t\tLaptop added successfully" << endl;
    cout << "\t\t\t============================================" << endl;

    {cout << "\n\t\t\tPress Enter to continue...";
    while (cin.get() != '\n');
    while (cin.get() != '\n');
    system("cls"); }
}
//------------------------------------------------------------------------------------------------------------------------------------------------
void updateSoldout() {
    Laptop* temp = new Laptop();

    cout << "\t\t\t1 - MSI  | 2 - DELL  | 3 - HP  | 4 - ASUS  | 5 - LENOVO \n";
    cout << "\t\t\tEnter the Laptop Brand Number : ";
    int model;
    cin >> model;
    temp->Brand = setLaptopBrand(model);

    cout << "\n\t\t\t1 - 4GB   | 2 - 8GB  | 3 - 16GB  | 4 - 32GB\n";
    cout << "\t\t\tEnter the Laptop RAM Number : ";
    int ram;
    cin >> ram;
    temp->RAM = setLaptopRam(ram);

    cout << "\n\t\t\t1 - i3   | 2 - i5  | 3 - i7 \n";
    cout << "\t\t\tEnter the Laptop Processor Number : ";
    int processor;
    cin >> processor;
    temp->Processor = setLaptopProcessor(processor);
    cout << "\n";

    cout << "\t\t\tEnter the Laptop Quantity :";
    int quantity;
    cin >> quantity;
    temp->Quantity = setLaptopQuantity(quantity);
    cout << "\n";

    Laptop* soldoutLaptop;
    soldoutLaptop = invetoryList.updateQuantity(temp);

    soldoutHistoryLast20.enQueue(soldoutLaptop);  //added soldout laptop Queue_History

    soldoutHistoryAll.insertLaptop(soldoutLaptop); //added soldout laptop Single_liked_list

    if (soldoutLaptop->Quantity >= 0) {
        cout << "\t\t\t==========================" << endl;
        cout << "\t\t\t   Successfully Updated" << endl;
        cout << "\t\t\t==========================" << endl;

    }

    {cout << "\n\t\t\tPress Enter to continue...";
    while (cin.get() != '\n');
    while (cin.get() != '\n');
    system("cls"); }

}

int histoyOption(int option) {
    switch (option)
    {
    case 1:
        soldoutHistoryLast20.printQueue();
        return -1;
    case 2:
        soldoutHistoryAll.showCase();
        return -1;
    default:
        cout << "\n\t\t\tInvalid Option, Enter the Correct Option: ";
        int reOptiont;
        cin >> reOptiont;
        return histoyOption(reOptiont);
    }

}
void soldoutHistory() {
    cout << "\t\t\t===============================================================\n";
    cout << "\t\t\t                 --->  Sales History  <---\n";
    cout << "\t\t\t===============================================================\n\n";
    cout << "\t\t\t\t\t 1 - Last 20 Soldout History\n" << endl;
    cout << "\t\t\t\t\t 2 - All Soldout History\n" << endl;

    cout << "\t\t\t\t\t Enter the Option: ";
    int option;
    cin >> option;
    system("cls");

    histoyOption(option);
}
//------------------------------------------------------------------------------------------------------------------------------------------------

void sortLaptop() {
    cout << "\t\t\t=================================================\n";
    cout << "\t\t\tACCORDING TO HOW MANY PREFERENCE YOU NEED TO SORT" << endl;
    cout << "\t\t\t=================================================\n\n";
    cout << "\t\t\t\t\t1 - Brand" << endl;
    cout << "\t\t\t\t\t2 - RAM" << endl;
    cout << "\t\t\t\t\t3 - Processor" << endl;
    cout << "\t\t\t\t\t4 - Brand & Processor" << endl;
    cout << "\t\t\t\t\t5 - Processor & RAM" << endl;
    cout << "\t\t\t\t\t6 - RAM & Brand" << endl;
    cout << "\t\t\t\t\t7 - Brand, Processor & RAM" << endl;
    cout << "\t\t\t\t\t8 - Main Menu" << endl;
    cout << "\n\t\t\t\t\tEnter Your Option: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\n\t\t\t1 - MSI  | 2 - DELL  | 3 - HP  | 4 - ASUS  | 5 - LENOVO \n";
        cout << "\t\t\tEnter the Laptop Brand Number : ";
        int model;
        cin >> model;
        invetoryList.onePreferenceBrand(model);
        break;
    case 2:
        cout << "\n\t\t\t1 - 4GB   | 2 - 8GB  | 3 - 16GB  | 4 - 32GB\n";
        cout << "\t\t\tEnter the Laptop RAM Number : ";
        int ram;
        cin >> ram;
        invetoryList.onePreferenceRam(ram);
        break;
    case 3:
        cout << "\n\t\t\t1 - i3   | 2 - i5  | 3 - i7 \n";
        cout << "\t\t\tEnter the Laptop Processor Number : ";
        int processor;
        cin >> processor;
        invetoryList.onePreferenceProcessor(processor);
        break;
    case 4:
        cout << "\n\t\t\t1 - MSI  | 2 - DELL  | 3 - HP  | 4 - ASUS  | 5 - LENOVO \n";
        cout << "\t\t\tEnter the Laptop Brand Number : ";
        int model1;
        cin >> model1;

        cout << "\n\t\t\t1 - i3   | 2 - i5  | 3 - i7 \n";
        cout << "\t\t\tEnter the Laptop Processor Number : ";
        int processor1;
        cin >> processor1;
        invetoryList.twoPreferenceProcessorBrand(model1, processor1);
        break;
    case 5:
        cout << "\n\t\t\t1 - 4GB   | 2 - 8GB  | 3 - 16GB  | 4 - 32GB\n";
        cout << "\t\t\tEnter the Laptop RAM Number : ";
        int ram1;
        cin >> ram1;

        cout << "\n\t\t\t1 - i3   | 2 - i5  | 3 - i7 \n";
        cout << "\t\t\tEnter the Laptop Processor Number : ";
        int processor2;
        cin >> processor2;
        invetoryList.twoPreferenceProcessorRam(ram1, processor2);
        break;
    case 6:
        cout << "\n\t\t\t1 - MSI  | 2 - DELL  | 3 - HP  | 4 - ASUS  | 5 - LENOVO \n";
        cout << "\t\t\tEnter the Laptop Brand Number : ";
        int model2;
        cin >> model2;

        cout << "\n\t\t\t1 - 4GB   | 2 - 8GB  | 3 - 16GB  | 4 - 32GB\n";
        cout << "\t\t\tEnter the Laptop RAM Number : ";
        int ram2;
        cin >> ram2;
        invetoryList.twoPreferenceBrandRam(model2, ram2);
        break;
    case 7:
        cout << "\n\t\t\t1 - MSI  | 2 - DELL  | 3 - HP  | 4 - ASUS  | 5 - LENOVO \n";
        cout << "\t\t\tEnter the Laptop Brand Number : ";
        int model3;
        cin >> model3;

        cout << "\n\t\t\t1 - 4GB   | 2 - 8GB  | 3 - 16GB  | 4 - 32GB\n";
        cout << "\t\t\tEnter the Laptop RAM Number : ";
        int ram3;
        cin >> ram3;

        cout << "\n\t\t\t1 - i3   | 2 - i5  | 3 - i7 \n";
        cout << "\t\t\tEnter the Laptop Processor Number : ";
        int processor3;
        cin >> processor3;
        invetoryList.threePreference(model3, ram3, processor3);
        break;

    case 8:
        system("cls");
        //Back to Main Menu
        break;

    default:
        cout << "\n\t\t\tYou Entered Wrong Option\n";
        {cout << "\n\t\t\tPress Enter to continue...";
        while (cin.get() != '\n');
        while (cin.get() != '\n');
        system("cls"); }
        sortLaptop();

        break;
    }
}
//------------------------------------------------------------------------------------------------------------------------------------------------
void login()
{
   
    string userName, password, name, pass;
    system("cls");

    cout << "\n\t\t\t\t\t\t LOGIN PAGE\n";
    cout << "\t\t\t\t\t<<<---------------------->>>\n\n";

    cout << "\t\t\t\t\tUSERNAME: ";
    cin >> userName;
    cout << "\t\t\t\t\tPASSWORD: ";
    cin >> password;

    ifstream input("PASSWORD.txt");
    bool existPassword = false;
    while (input >> name >> pass)
    {
        if (name == userName && pass == password)
        {
            existPassword = true;
            system("cls");
        }
    }
    input.close();

    if (existPassword)
    {
        adminPannal();
    }
    else
    {
        cout << "\n\t\t\t\t\tPlease check your Username and Password \n";
        {cout << "\n\t\t\t\t\tPress Enter to continue...";
        while (cin.get() != '\n');
        while (cin.get() != '\n');
        system("cls"); }

        main();
    }
}

void forgot()
{
    int option;
    system("cls");
    cout << "\n\t\t\t\t\t\tFORGOT PASSWORD\n";
    cout << "\t\t\t\t\t<<<------------------------>>>\n\n" ;
    cout << "\t\t\t\t\t1 - Search Username\n";
    cout << "\t\t\t\t\t2 - Main Menu\n\n";
    cout << "\t\t\t\t\tEnter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        bool existPassword = false;
        string userName, sname, spass;
        cout << "\n\t\t\t\t\tEnter your username: ";
        cin >> userName;

        ifstream f2("PASSWORD.txt");
        while (f2 >> sname >> spass)
        {
            if (sname == userName)
            {
                existPassword = true;
                break;
            }
        }
        f2.close();
        if (existPassword)
        {
            cout << "\n\t\t\t\t\tYour account is found!\n";
            cout << "\t\t\t\t\tYour password is: " << spass << "\n";
            {cout << "\n\t\t\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }
            main();
        }
        else
        {
            cout << "\n\t\t\t\t\tSorry, Your account was not found\n";
            {cout << "\n\t\t\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }
            main();
        }
        break;
    }
    case 2:
        system("cls");
        main();
        break;

    default:
        system("cls");
        cout << "\n\t\t\tPlease try again.\n";
        forgot();
        break;
    }
}
//------------------------------------------------------------------------------------------------------------------------------------------------
void adminPannal() {
    system("color 0B");

    do
    {
        cout << "\n\t\t\t===============================================================" << endl;
        cout << "\t\t\t\t\t\t---> Menu <---" << endl;
        cout << "\t\t\t===============================================================" << endl;
        cout << "\n\t\t\t\t\t 1 - Low stock Updates" << endl;
        cout << "\t\t\t\t\t 2 - Inventory List" << endl;
        cout << "\t\t\t\t\t 3 - Sorting Option" << endl;
        cout << "\t\t\t\t\t 4 - Sales History" << endl;
        cout << "\t\t\t\t\t 5 - Add New Stock" << endl;
        cout << "\t\t\t\t\t 6 - Update Sold-Out Details" << endl;
        cout << "\t\t\t\t\t 7 - Exit the Program" << endl;

        cout << "\n\t\t\t\t\t Enter the Option: ";
        int option;
        cin >> option;
        system("cls");


        switch (option)
        {
        case 1:
            invetoryList.lowStockUpdates();
            break;
        case 2:
            invetoryList.showCase();
            break;
        case 3:
            sortLaptop();
            break;
        case 4:
            soldoutHistory();
            break;
        case 5:
            addLaptop();
            break;
        case 6:
            updateSoldout();
            break;
        case 7:
        {cout << "\n\t\t\tPress Enter to exit...";
        while (cin.get() != '\n');
        while (cin.get() != '\n');
        system("cls");
        system("exit");
        }
        return;
        default:
            cout << "\n\t\t\tInvalid Option\n";
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }
        }

    } while (true);
}