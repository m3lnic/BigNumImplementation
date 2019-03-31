#pragma once

// > Includes
#include <vector>
#include <iostream>

// > Holds a single value at 4 bits
// > TODO(Mel): Make it so that the inserted value cannot be more than 4 bits or 1 hex of value
// > TODO(Mel): Convert this to its own class with it's own functions
typedef struct Single_Value {
	unsigned int value : 4;
};

// > Methods and data for the application
// > TODO(Mel): Complete all functions wanted
// > TODO(Mel): Testing
class dataArray {
	public:
		// > --- Constructors /  Deconstructors ---
		dataArray();
		dataArray(std::vector<Single_Value>& initialiser);
		~dataArray();

		// > --- Methods --- 
		// > Will append to the end
		bool append(unsigned int data);
		bool append(std::vector<Single_Value>& appending);

		// > Will insert at location
		bool insert(unsigned int data, unsigned int index);
		bool insert(std::vector<Single_Value>& insertion, unsigned int index);

		// > Prints the data of this array
		void print();
		void printPosition(unsigned int index);

		// > Returns data at the provided index
		unsigned int getData(int index);

		// > Returns the character version of a Single_Value
		// > 0x0 -> 0x9 = normal
		// > 0xA		= Decimal Point
		// > 0xF		= Null Terminator
		char convertValueToChar(Single_Value& converting);

		// > --- Operators ---
			// > In operators, do not return copies of what we are performing the operators on
			// > This is because these may already use a lot of memory to store the data
		// > Data
		// > unsigned int operator [](int x);

		// > Arithmetic
		std::vector<Single_Value>& operator +(std::vector<Single_Value>& toAdd);
		std::vector<Single_Value>& operator -(std::vector<Single_Value>& toSub);
		std::vector<Single_Value>& operator *(std::vector<Single_Value>& toMul);
		std::vector<Single_Value>& operator /(std::vector<Single_Value>& toDiv);
		std::vector<Single_Value>& operator %(std::vector<Single_Value>& toMod);

		// > Relational
		std::vector<Single_Value> operator ==(std::vector<Single_Value>& toAdd);
		std::vector<Single_Value> operator !=(std::vector<Single_Value>& toAdd);

		// > Logical

		// > Bitwise
		
		// > Assignment

		// > Ternary
	private:
		// > Make this inaccessible except through functions
		std::vector<Single_Value>* array;
};
