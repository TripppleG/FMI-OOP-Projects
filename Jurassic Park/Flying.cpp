#include "Flying.h"
#include <time.h>

Flying::Flying(const char* name, const Sex sex, const Era era, const char* species) : Dinosaur(name, sex, era, species)
{
	srand((unsigned)time(0));

	category = Category::Flying;
	if (rand()%5 == 4)
	{
		food = Food::Fish;
	}
	else
	{
		food = Food::Meat;
	}
}

Dinosaur* Flying::Clone() const
{
	Dinosaur* copy = new Flying(*this);
	return copy;
}
