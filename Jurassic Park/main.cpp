#include "Cage.h"
#include <fstream>
#include <iostream>

enum class Fruit
{
	apple = 1,
	orange,
	banana,
	kiwi = -1
};

int main()
{
	//Dinosaur* d = new Flying("Gosho", Sex::Female, Era::Triassic, "Brontosaur");
	std::cout << (int)Fruit::apple;
	return 0;
}	