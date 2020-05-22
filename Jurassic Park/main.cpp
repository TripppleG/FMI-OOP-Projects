#include "JurassicParkUI.h"
#include <fstream>
#include <iostream>
#include <iomanip>



const char* SetName(const char* name)
{
	int length = strlen(name);
	char* name2 = new char[length + 1];
	if (length == 0)
	{
		throw std::invalid_argument("Name can't be empty");
	}
	for (int i = 0; i < length; i++)
	{
		if (tolower(name[i]) < 'a' || tolower(name[i]) > 'z')
		{
			throw std::invalid_argument("Name can't contain non-letter characters!s");
		}
	}
	strcpy_s(name2, length + 1, name);
	return name2;
}
enum class Fruit
{
	apple = 1, 
	banana, 
	orange,
	kiwi
};
int main()
{
	/*std::fstream file("ParkInfo.txt", std::ios::in | std::ios::out | std::ios::trunc);
	DinosaurPark p;
	Dinosaur a("Gosho", Sex::Female, Era::Triassic, "Brontosaur", Category::Flying);
	Dinosaur b("Pesho", Sex::Male, Era::Jurassic, "Jesus", Category::Herbivores);
	Dinosaur c("Dsjandsadsad", Sex::Male, Era::Jurassic, "hgtrbhvfd", Category::Carnivorous);
	Dinosaur d("GoFuckYourSelfFFS", Sex::Female, Era::Cretaceous, "LinkinPark", Category::Aquatic);
	p.AddDinosaur(a);
	p.AddDinosaur(b);
	p.AddDinosaur(c);
	p.AddDinosaur(d);*/
	//file << p;
	JurrasicPark d;
	
	return 0;
}	