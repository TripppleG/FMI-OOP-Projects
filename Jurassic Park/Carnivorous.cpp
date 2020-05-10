#include "Carnivorous.h"

Carnivorous::Carnivorous(const char* name, const Sex sex, const Era era, const char* species) : Dinosaur(name, sex, era, species)
{
	category = Category::Carnivorous;
	food = Food::Meat;
}

Dinosaur* Carnivorous::Clone() const
{
	Dinosaur* copy = new Carnivorous(*this);
	return copy;
}
