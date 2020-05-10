#pragma once
#include "Dinosaur.h"

class Aquatic: public Dinosaur
{
public:
	Aquatic() : Dinosaur() { category = Category::InvalidCategory; food = Food::InvalidFood; }
	Aquatic(const char* name, const Sex sex, const Era era, const char* species);
	Dinosaur* Clone()const;
};