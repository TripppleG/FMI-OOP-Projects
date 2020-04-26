#include "Cage.h"
#include <fstream>

int main()
{
	Dinosaur* d = new Aquatic("Gosho", 'F', "Triassic", "Brontosaur");
	Dinosaur* c = new Aquatic;

	std::fstream file("ParkInfo.txt");
	file >> *c;
	std::cout << *c;
	

	return 0;
}	