#include "Herbivores.h"

void Herbivores::SetCategory()
{
	this->category = new char[11];
	strcpy_s(this->category, 11, "Herbivores");
}

void Herbivores::SetFood()
{
	this->food = new char[6];
	strcpy_s(this->food, 6, "Grass");
}

Herbivores::Herbivores(const char* name, const char sex, const char* era, const char* species) : Dinosaur(name, sex, era, species)
{
	SetCategory();
	SetFood();
}

Herbivores::Herbivores(const Herbivores& other) : Dinosaur(other) 
{
	SetCategory();
	SetFood();
}

Herbivores& Herbivores::operator=(const Herbivores& other)
{
	Dinosaur::operator=(other);
	SetCategory();
	SetFood();
	return *this;
}

Dinosaur* Herbivores::Clone() const
{
	Dinosaur* copy = new Herbivores(*this);
	return copy;
}
