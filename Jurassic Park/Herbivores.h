#pragma once
#include "Dinosaur.h"

class Herbivores : public Dinosaur
{
public:
	Herbivores() : Dinosaur() { category = Category::InvalidCategory; food = Food::InvalidFood; }
	Herbivores(const char* name, const Sex sex, const Era era, const char* species);
	Dinosaur* Clone() const;
};