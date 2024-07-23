#pragma once
//#pragma once
#include <iostream>
#include <stdlib.h>
#include <String>
#include <cstddef>
#include "Laptop.h"


class Queue_History
{
private:
	int size;
	int capacity;
	int front; // position of beginning of queue
	int rear;   //position of ending of queue
	Laptop* data;
public:
	Queue_History()
	{
		capacity = 10;
		size = 0;
		data = new Laptop[capacity];
		front = 0;
		rear = 0;
	}

	void deQueue() {
		if (size == 0) {
			cout << "\t\t\tEmpty History" << endl;
		}
		else {
			Laptop temp = data[front];	//take the value from the front of the queue
			front = (front + 1) % capacity;	//increment front and reset to 0, if reaches cap
			size--;
			
		}
	}

	void enQueue(Laptop* val) {
		if (val->Quantity >= 0) {
			if (size == capacity) {
				deQueue();
				enQueue(val); // Recorsion call
			}
			else {
				data[rear] = *val;	//insert value at the rear
				rear = (rear + 1) % capacity;	
				size++;
			}
		}
		
	}

	void printQueue() {
		if (size == 0) {
			cout << "\t\t\tEmpty History" << endl;
		}
		else {
			int index = front;
			cout << "\t\t\t ----------------------------------------------\n";
			cout << "\t\t\t | Brand  |  RAM | Processor | Quantity & Price \n";
			cout << "\t\t\t ----------------------------------------------\n";
			for (int i = 0; i < size; i++) {
				cout << "\t\t\t | " << data[index].Brand << " | ";
				cout << data[index].RAM << " |    ";
				cout << data[index].Processor << "     | ";
				cout << data[index].Quantity << " - ";
				cout << data[index].Price << "/-" << "\n";

				
				index = (index + 1) % capacity;
			}
		}
		
		cout << endl;
		{cout << "\t\t\tPress Enter to continue...";
		while (cin.get() != '\n');
		while (cin.get() != '\n');
		system("cls"); }
	}


};