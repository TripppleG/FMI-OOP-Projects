#include "Aquatic.h"

void Aquatic::SetCategory()
{
	this->category = new char[8];
	strcpy_s(this->category, 8, "Aquatic");
}

void Aquatic::SetFood()
{
	this->food = new char[5];
	strcpy_s(this->food, 5, "Fish");
}

Aquatic::Aquatic(const char* name, const char sex, const char* era, const char* species) : Dinosaur(name, sex, era, species)
{
	SetCategory();
	SetFood();
}

Aquatic::Aquatic(const Aquatic& other) : Dinosaur(other) 
{
	SetCategory();
	SetFood();
}

Aquatic& Aquatic::operator=(const Aquatic& other)
{
	Dinosaur::operator=(other);
	SetCategory();
	SetFood();
	return *this;
}

Dinosaur* Aquatic::Clone() const
{
	Dinosaur* copy = new Aquatic(*this);
	return copy;
}
