#include "Flying.h"
#include <time.h>

void Flying::SetCategory()
{
	this->category = new char[7];
	strcpy_s(this->category, 7,"Flying");
}

void Flying::SetFood()
{
	this->food = new char[5];
	srand(time(0));
	if (rand() % 5 < 4)
	{
		strcpy_s(this->food, 5, "Meat");
	}
	else
	{
		strcpy_s(this->food, 5, "Fish");
	}
}

Flying::Flying(const char* name, const char sex, const char* era, const char* species) : Dinosaur(name, sex, era, species)
{
	SetCategory();
	SetFood();
}

Flying::Flying(const Flying& other) : Dinosaur(other) 
{
	SetCategory();
	int len = strlen(other.food);
	food = new char[len + 1];
	strcpy_s(food, len + 1, other.food);
}

Flying& Flying::operator=(const Flying& other)
{
	Dinosaur::operator=(other);
	SetCategory();
	int len = strlen(other.food);
	food = new char[len + 1];
	strcpy_s(food, len + 1, other.food);
	return *this;
}

Dinosaur* Flying::Clone() const
{
	Dinosaur* copy = new Flying(*this);
	return copy;
}
