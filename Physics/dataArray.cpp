#include "dataArray.h"

// > --- Constructors /  Deconstructors ---
dataArray::dataArray() {

}

dataArray::dataArray(std::vector<Single_Value>& initialiser) {
	this->append(initialiser);
}

dataArray::~dataArray() {
	this->array->clear();
}

// > --- Methods --- 
// > Will append to the end  - Returns false if it fails
bool dataArray::append(unsigned int data) {
	// > TODO(Mel): Look at implementing this check into a private function?
	if (data < 0x0 || data > 0xF) // > Is the data being passed valid? 
		return false;

	this->array->push_back(Single_Value{ data }); // > Append to the end
	return true;
}

bool dataArray::append(std::vector<Single_Value>& appending) {
	// > Loop through the data that we are adding
	for (int i = 0; i < appending.size(); i++) {
		if (this->append(appending[i].value) == false)
			return false;
	}

	return true;
}

// > Will insert at location
bool dataArray::insert(unsigned int data, unsigned int index) {
	if (data < 0x0 || data > 0xF)
		return false;

	// > Inset at the position of the first element + the index
	this->array->insert(this->array->begin() + index, Single_Value{ data });
}

// > TODO(Mel): Implement error detection here
// >	Though it should be done in the Single_Value class when that is ready
bool dataArray::insert(std::vector<Single_Value>& insertion, unsigned int index) {
	for (int i = 0; i < insertion.size(); i++) {
		this->array->insert(this->array->begin() + index + i, insertion[i]);
	}

	return true;
}

// > Prints the data of this array
void dataArray::print() {
	for (int i = 0; i < this->array->size(); i++) {
		std::cout << this->convertValueToChar(this->array->at(i));
	}
	std::cout << std::endl;
}

void dataArray::printPosition(unsigned int index) {
	std::cout << this->convertValueToChar(this->array->at(index)) << std::endl;
}

// > Returns data at the provided index
unsigned int dataArray::getData(int index) {
	return this->array->at(index).value;
}

// > Returns the character version of a Single_Value
// > TODO(Mel): Move this to the Single_Value class when it is created
// > 0x0 -> 0x9 = normal
// > 0xA		= Decimal Point
// > 0xF		= Null Terminator
char dataArray::convertValueToChar(Single_Value& converting) {
	switch (converting.value)
	{
		case 0x0: {
			return '0';
			break;
		}
		case 0x1: {
			return '1';
			break;
		}
		case 0x2: {
			return '2';
			break;
		}
		case 0x3: {
			return '3';
			break;
		}
		case 0x4: {
			return '4';
			break;
		}
		case 0x5: {
			return '5';
			break;
		}
		case 0x6: {
			return '6';
			break;
		}
		case 0x7: {
			return '7';
			break;
		}
		case 0x8: {
			return '8';
			break;
		}
		case 0x9: {
			return '9';
			break;
		}
		case 0xA: {
			return '.';
			break;
		}
		case 0xB: {
			return 'U';
			break;
		}
		case 0xC: {
			return 'U';
			break;
		}
		case 0xD: {
			return 'U';
			break;
		}
		case 0xE: {
			return 'U';
			break;
		}
		case 0xF: {
			return '\0';
			break;
		}
		// > If we reach here, F will be the error handler
		default: {
			return 'F';
			break;
		}
	}
}

// > --- Operators ---
	// > In operators, do not return copies of what we are performing the operators on
	// > This is because these may already use a lot of memory to store the data
// > Data
// > unsigned int dataArray::operator [](int x) {}

// > Arithmetic
std::vector<Single_Value>& dataArray::operator +(std::vector<Single_Value>& toAdd) {
	// > Running the loop from right to left
	unsigned int carryOver = 0;
	for (int i = this->array->size() - 1; i >= 0; i++) {
		int intValueToAdd = (toAdd[i].value + carryOver);
		int oldValue = this->array->at[i].value;
		this->array->at[i].value = (oldValue + intValueToAdd) % 10;
	}
}

std::vector<Single_Value>& dataArray::operator -(std::vector<Single_Value>& toSub){}
std::vector<Single_Value>& dataArray::operator *(std::vector<Single_Value>& toMul){}
std::vector<Single_Value>& dataArray::operator /(std::vector<Single_Value>& toDiv){}
std::vector<Single_Value>& dataArray::operator %(std::vector<Single_Value>& toMod){}

// > Relational
std::vector<Single_Value> dataArray::operator ==(std::vector<Single_Value>& toAdd){}
std::vector<Single_Value> dataArray::operator !=(std::vector<Single_Value>& toAdd){}

// > Logical

// > Bitwise

// > Assignment

// > Ternary