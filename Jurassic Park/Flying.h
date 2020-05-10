#pragma once
#include "Dinosaur.h"

class Flying : public Dinosaur
{
public:
	Flying() : Dinosaur() { category = Category::InvalidCategory; food = Food::InvalidFood; }
	Flying(const char* name, const Sex sex, const Era era, const char* species);
	Dinosaur* Clone() const;
};