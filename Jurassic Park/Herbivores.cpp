#include "Herbivores.h"

Herbivores::Herbivores(const char* name, const Sex sex, const Era era, const char* species) : Dinosaur(name, sex, era, species)
{
	category = Category::Herbivores;
	food = Food::Grass;
}

Dinosaur* Herbivores::Clone() const
{
	Dinosaur* copy = new Herbivores(*this);
	return copy;
}
