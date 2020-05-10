#include "Aquatic.h"

Aquatic::Aquatic(const char* name, const Sex sex, const Era era, const char* species) : Dinosaur(name, sex, era, species)
{
	category = Category::Aquatic;
	food = Food::Fish;
}

Dinosaur* Aquatic::Clone() const
{
	Dinosaur* copy = new Aquatic(*this);
	return copy;
}
