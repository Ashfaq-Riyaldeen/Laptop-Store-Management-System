#pragma once
#include <iostream>
#include <String>
#include <cstddef>
#include <stdlib.h>

using namespace std;

class Laptop {

public:
	string Brand;
	string Processor;
	string RAM;
	int Quantity;
	int Price;

	Laptop() {
		Brand = "";
		Processor = "";
		RAM = "";
		Quantity = -1;
		Price = -1;
	}

	Laptop(string brand, string processor, string ram, int quantity, int price) {
		Brand = brand;
		Processor = processor;
		RAM = ram;
		Quantity = quantity;
		Price = price;
	}

};

