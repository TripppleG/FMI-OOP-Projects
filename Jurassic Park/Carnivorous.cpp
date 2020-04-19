#include "Carnivorous.h"

void Carnivorous::SetCategory()
{
	this->category = new char[12];
	strcpy_s(this->category, 12, "Carnivorous");
}

void Carnivorous::SetFood()
{
	this->food = new char[5];
	strcpy_s(this->food, 5, "Meat");
}

Carnivorous::Carnivorous(const char* name, const char sex, const char* era, const char* species) : Dinosaur(name, sex, era, species)
{
	SetCategory();
	SetFood();
}

Carnivorous::Carnivorous(const Carnivorous& other) : Dinosaur(other) 
{
	SetCategory();
	SetFood();
}

Carnivorous& Carnivorous::operator=(const Carnivorous& other)
{
	Dinosaur::operator=(other);
	SetCategory();
	SetFood();
	return *this;
}

Dinosaur* Carnivorous::Clone() const
{
	Dinosaur* copy = new Carnivorous(*this);
	return copy;
}
