#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

typedef struct Data {
	unsigned int data : 4;
};

void main() {
	std::cout << "Loading application :)" << std::endl;
	srand(time(NULL));


	std::vector<Data> data; // > Initialise at 0
	
	for (int i = 0; i < 300; i++) {
		data.push_back(Data{ (unsigned int)rand() % 10 }); // > 0 to 9
	}

	for (int i = 0; i < data.size(); i++) {
		std::cout << data[i].data;
	}
	std::cout << std::endl;
		
	std::cout << "Exiting application :)" << std::endl;
	std::getchar();
}