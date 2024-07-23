#pragma once
#include <iostream>
#include <stdlib.h>
#include <String>
#include <cstddef>
#include "Laptop.h"
#include "Queue_History.h"

using namespace std;


class Node
{
public:

    Laptop* data;
    Node* next;

    Node(Laptop* Data) //overloaded constructor
    {
        data = Data;
        next = NULL;
    }
};

class Single_liked_list
{
private:
    Node* head;
    Node* tail;
    int size;

public:
    Single_liked_list() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    

    void insertLaptop(Laptop* Data){

        Node* temp = new Node(Data); //Create the node
        Node* current = head;

        if (temp->data->Quantity >= 0) {

            if (head == NULL) { //empty list   ; if (size==0)
                head = temp;
                tail = temp;
                size++;
            }
            else {
                bool alredy_exist_laptop = false;
                for (int i = 0; i < size; i++) {
                    if (temp->data->Brand == current->data->Brand && temp->data->RAM == current->data->RAM && temp->data->Processor == current->data->Processor) {
                        current->data->Quantity += temp->data->Quantity;
                        current->data->Price = temp->data->Price;
                        alredy_exist_laptop = true;
                    }
                    current = current->next;
                }

                if (alredy_exist_laptop == false)
                {
                    tail->next = temp;
                    tail = temp;
                    size++;
                }

            }
        }
        
    }

    Laptop* updateQuantity(Laptop* Data) {
        Node* temp = new Node(Data); //Create the node
        Node* current = head;

        if (head == NULL) { //empty list   ; if (size==0)
            cout << "\t\t\tStock is currently Empty" << endl;
            return new Laptop();
        }
        else {
            bool alredy_exist_laptop = false;
            for (int i = 0; i < size; i++) {
                if (temp->data->Brand == current->data->Brand && temp->data->RAM == current->data->RAM && temp->data->Processor == current->data->Processor) { 
                    alredy_exist_laptop = true;
                    break;
                }
                current = current->next;
            }

            if (alredy_exist_laptop == true)
            {
                if (current->data->Quantity >= temp->data->Quantity) {
                    current->data->Quantity = current->data->Quantity - temp->data->Quantity;

                    temp->data->Price = current->data->Price;
                    return temp->data;
                }
                else {
                    cout << "\t\t\tThe Quantity You Entered Currently Doesn't Exist in Stock" << endl;
                    return new Laptop();
                }
            }
            else {
                cout << "\t\t\tThis Laptop Doesn't Exist in Stock" << endl;
                return new Laptop();
            }

        }
    }

    void showCase() {
        Node* current = head;

        if (size == 0) {
            cout << "\t\t\tNo laptop in the store\n";
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }
        }
        else {
            cout << "\t\t\t----------------------------------------------\n";
            cout << "\t\t\t| Brand  |  RAM | Processor | Quantity & Price \n";
            cout << "\t\t\t----------------------------------------------\n";
            for (int i=0; i < size; i++) {
                cout << "\t\t\t| " << current->data->Brand << " | ";
                cout << current->data->RAM << " |    ";
                cout << current->data->Processor << "     | ";
                cout << current->data->Quantity << " - ";
                cout << current->data->Price << "/-" << "\n";

                current=current->next;
            }
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }

        }
    }
    
    void lowStockUpdates() {

        Node* current = head;

        if (size == 0) {
            cout << "\t\t\tNo laptop in the store\n";
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }
        }
        else {
            bool lowStock = false;
            cout << "\t\t\t----------------------------------------------\n";
            cout << "\t\t\t| Brand  |  RAM | Processor | Quantity & Price \n";
            cout << "\t\t\t----------------------------------------------\n";
            for (int i = 0; i < size; i++) {
                if (current->data->Quantity<6) {
                    cout << "\t\t\t| " << current->data->Brand << " | ";
                    cout << current->data->RAM << " |    ";
                    cout << current->data->Processor << "     | ";
                    cout << current->data->Quantity << " - ";
                    cout << current->data->Price << "/-" << "\n";

                    lowStock = true;
                }
                current = current->next;
            }
            if (!lowStock) {
                cout << "\t\t\tAll Laptops Stocks are Up to Five Units\n";
            }
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }

        }
    }

    void onePreferenceBrand(int option) {
        string brand = "";
        if (option == 1) {
            brand = "MSI   ";
        }
        else if(option == 2) {
            brand = "DELL  ";
        }
        else if (option == 3) {
            brand = "HP    ";
        }
        else if (option == 4) {
            brand = "ASUS  ";
        }
        else if (option == 5) {
            brand = "LENOVO";
        }
        else {
            system("cls");
            return;
        }

        Node* current = head;

        if (size == 0) {
            cout << "\n\t\t\tNo laptop in the store\n";
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }
        }
        else {
            system("cls");
            cout << "\t\t\tSorted by "  << "Brand: "<< brand << "\n\n";
            cout << "\t\t\t----------------------------------------------\n";
            cout << "\t\t\t| Brand  |  RAM | Processor | Quantity & Price \n";
            cout << "\t\t\t----------------------------------------------\n";
            for (int i = 0; i < size; i++) {
                if (current->data->Brand == brand) {
                    cout << "\t\t\t| " << current->data->Brand << " | ";
                    cout << current->data->RAM << " |    ";
                    cout << current->data->Processor << "     | ";
                    cout << current->data->Quantity << " - ";
                    cout << current->data->Price << "/-" << "\n";
                }
                current = current->next;
            }
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }

        }
       
    }

    void onePreferenceRam(int option) {
       // 1 - 4GB | 2 - 8GB | 3 - 16GB | 4 - 32GB
        string ram = "";
        if (option == 1) {
            ram = " 4GB";
        }
        else if (option == 2) {
            ram = " 8GB";
        }
        else if (option == 3) {
            ram = "16GB";
        }
        else if (option == 4) {
            ram = "32GB";
        }
        else {
            system("cls");
            return;
        }

        Node* current = head;

        if (size == 0) {
            cout << "\t\t\tNo laptop in the store\n";
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }
        }
        else {
            system("cls");
            cout << "\t\t\tSorted by " << " ram: " << ram <<"\n\n";
            cout << "\t\t\t----------------------------------------------\n";
            cout << "\t\t\t| Brand  |  RAM | Processor | Quantity & Price \n";
            cout << "\t\t\t----------------------------------------------\n";
            for (int i = 0; i < size; i++) {
                if (current->data->RAM == ram) {
                    cout << "\t\t\t| " << current->data->Brand << " | ";
                    cout << current->data->RAM << " |    ";
                    cout << current->data->Processor << "     | ";
                    cout << current->data->Quantity << " - ";
                    cout << current->data->Price << "/-" << "\n";
                }
                current = current->next;
            }
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }

        }

    }

    void onePreferenceProcessor(int option) {
      
        string processor = "";
        if (option == 1) {
            processor = "i3";
        }
        else if (option == 2) {
            processor = "i5";
        }
        else if (option == 3) {
            processor = "i7";
        }
        else {
            system("cls");
            return;
        }

        Node* current = head;

        if (size == 0) {
            cout << "\t\t\tNo laptop in the store\n";
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }
        }
        else {
            system("cls");
            cout << "\t\t\tSorted by "  << "Processor: " << processor<< "\n\n";
            cout << "\t\t\t----------------------------------------------\n";
            cout << "\t\t\t| Brand  |  RAM | Processor | Quantity & Price \n";
            cout << "\t\t\t----------------------------------------------\n";
            for (int i = 0; i < size; i++) {
                if (current->data->Processor == processor) {
                    cout << "\t\t\t| " << current->data->Brand << " | ";
                    cout << current->data->RAM << " |    ";
                    cout << current->data->Processor << "     | ";
                    cout << current->data->Quantity << " - ";
                    cout << current->data->Price << "/-" << "\n";
                }
                current = current->next;
            }
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }

        }

    }

    void twoPreferenceProcessorBrand(int option1, int option2) {
        
        string brand = "";
        string processor = "";

        if (option1 == 1) {
            brand = "MSI   ";

        }
        else if (option1 == 2) {
            brand = "DELL  ";
        }
        else if (option1 == 3) {
            brand = "HP    ";
        }
        else if (option1 == 4) {
            brand = "ASUS  ";
        }
        else if (option1 == 5) {
            brand = "LENOVO";
        }
        else {
            system("cls");
            return;
        }
        
        if (option2 == 1) {
            processor = "i3";
        }
        else if (option2 == 2) {
            processor = "i5";
        }
        else if (option2 == 3) {
            processor = "i7";
        }
        else {
            system("cls");
            return;
        }

        Node* current = head;

        if (size == 0) {
            cout << "\t\t\tNo laptop in the store\n";
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }
        }
        else {
            system("cls");
            cout << "\t\t\tSorted by " << " Brand: " << brand << " Processor: " << processor <<"\n\n";
            cout << "\t\t\t----------------------------------------------\n";
            cout << "\t\t\t| Brand  |  RAM | Processor | Quantity & Price \n";
            cout << "\t\t\t----------------------------------------------\n";
            for (int i = 0; i < size; i++) {
                if (current->data->Processor == processor && current->data->Brand == brand) {
                    cout << "\t\t\t| " << current->data->Brand << " | ";
                    cout << current->data->RAM << " |    ";
                    cout << current->data->Processor << "     | ";
                    cout << current->data->Quantity << " - ";
                    cout << current->data->Price << "/-" << "\n";
                }
                current = current->next;
            }
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }

        }

    }
    
    void twoPreferenceProcessorRam(int option1, int option2) {
        
        string ram = "";
        string processor = "";

        if (option1 == 1) {
            ram = " 4GB";
        }
        else if (option1 == 2) {
            ram = " 8GB";
        }
        else if (option1 == 3) {
            ram = "16GB";
        }
        else if (option1 == 4) {
            ram = "32GB";
        }
        else {
            system("cls");
            return;
        }

        if (option2 == 1) {
            processor = "i3";
        }
        else if (option2 == 2) {
            processor = "i5";
        }
        else if (option2 == 3) {
            processor = "i7";
        }
        else {
            system("cls");
            return;
        }

        Node* current = head;

        if (size == 0) {
            cout << "\t\t\tNo laptop in the store\n";
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }
        }
        else {
            for (int i = 0; i < size; i++) {
                system("cls");
                cout << "\t\t\tSorted by " << " Processor: " << processor << " RAM: "<< ram <<"\n\n";
                cout << "\t\t\t----------------------------------------------\n";
                cout << "\t\t\t| Brand  |  RAM | Processor | Quantity & Price \n";
                cout << "\t\t\t----------------------------------------------\n";
                if (current->data->Processor == processor && current->data->RAM == ram) {
                    cout << "\t\t\t| " << current->data->Brand << " | ";
                    cout << current->data->RAM << " |    ";
                    cout << current->data->Processor << "     | ";
                    cout << current->data->Quantity << " - ";
                    cout << current->data->Price << "/-" << "\n";
                }
                current = current->next;
            }
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }

        }

    }

    void twoPreferenceBrandRam(int option1, int option2) {

        string brand = "";
        string ram = "";

        if (option1 == 1) {
            brand = "MSI   ";

        }
        else if (option1 == 2) {
            brand = "DELL  ";
        }
        else if (option1 == 3) {
            brand = "HP    ";
        }
        else if (option1 == 4) {
            brand = "ASUS  ";
        }
        else if (option1 == 5) {
            brand = "LENOVO";
        }
        else {
            system("cls");
            return;
        }

        if (option2 == 1) {
            ram = " 4GB";
        }
        else if (option2 == 2) {
            ram = " 8GB";
        }
        else if (option2 == 3) {
            ram = "16GB";
        }
        else if (option2 == 4) {
            ram = "32GB";
        }
        else {
            system("cls");
            return;
        }

        Node* current = head;

        if (size == 0) {
            cout << "\t\t\tNo laptop in the store\n";
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }
        }
        else {
            system("cls");
            cout << "\t\t\tSorted by " << " Brand: " << brand << " RAM: "<< ram<<"\n\n";
            cout << "\t\t\t----------------------------------------------\n";
            cout << "\t\t\t| Brand  |  RAM | Processor | Quantity & Price \n";
            cout << "\t\t\t----------------------------------------------\n";
            for (int i = 0; i < size; i++) {
                if (current->data->RAM == ram && current->data->Brand == brand) {
                    cout << "\t\t\t| " << current->data->Brand << " | ";
                    cout << current->data->RAM << " |    ";
                    cout << current->data->Processor << "     | ";
                    cout << current->data->Quantity << " - ";
                    cout << current->data->Price << "/-" << "\n";
                }
                current = current->next;
            }
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }

        }

    }

    void threePreference(int option1, int option2, int option3) {

        string brand = "";
        string ram = "";
        string processor = "";

        if (option1 == 1) {
            brand = "MSI   ";

        }
        else if (option1 == 2) {
            brand = "DELL  ";
        }
        else if (option1 == 3) {
            brand = "HP    ";
        }
        else if (option1 == 4) {
            brand = "ASUS  ";
        }
        else if (option1 == 5) {
            brand = "LENOVO";
        }
        else {
            system("cls");
            return;
        }

        if (option2 == 1) {
            ram = " 4GB";
        }
        else if (option2 == 2) {
            ram = " 8GB";
        }
        else if (option2 == 3) {
            ram = "16GB";
        }
        else if (option2 == 4) {
            ram = "32GB";
        }
        else {
            system("cls");
            return;
        }

        if (option3 == 1) {
            processor = "i3";
        }
        else if (option3 == 2) {
            processor = "i5";
        }
        else if (option3 == 3) {
            processor = "i7";
        }
        else {
            system("cls");
            return;
        }
        Node* current = head;

        if (size == 0) {
            cout << "\t\t\tNo laptop in the store\n";
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }
        }
        else {
            system("cls");
            cout << "\t\t\tSorted by Brand: " << brand << " Processor: " << processor << " RAM:" << ram <<"\n\n";
            cout << "\t\t\t----------------------------------------------\n";
            cout << "\t\t\t| Brand  |  RAM | Processor | Quantity & Price \n";
            cout << "\t\t\t----------------------------------------------\n";
            for (int i = 0; i < size; i++) {
                if (current->data->RAM == ram && current->data->Brand == brand && current->data->Processor== processor) {
                    cout << "\t\t\t| " << current->data->Brand << " | ";
                    cout << current->data->RAM << " |    ";
                    cout << current->data->Processor << "     | ";
                    cout << current->data->Quantity << " - ";
                    cout << current->data->Price << "/-" << "\n";
                }
                current = current->next;
            }
            {cout << "\n\t\t\tPress Enter to continue...";
            while (cin.get() != '\n');
            while (cin.get() != '\n');
            system("cls"); }

        }

    }
 };