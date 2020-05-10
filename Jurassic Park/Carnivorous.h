#pragma once
#include "Dinosaur.h"

class Carnivorous: public Dinosaur
{
public:
	Carnivorous() : Dinosaur() { category = Category::InvalidCategory; food = Food::InvalidFood; }
	Carnivorous(const char* name, const Sex sex, const Era era, const char* species);
	Dinosaur* Clone() const;
};