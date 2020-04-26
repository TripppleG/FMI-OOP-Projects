#pragma once
#include "Dinosaur.h"

class Aquatic: public Dinosaur
{
private:
	void SetCategory();
	void SetFood();
public:
	Aquatic() : Dinosaur() { SetCategory(); SetFood(); }
	Aquatic(const char* name, const char sex, const char* era, const char* species);
	Aquatic(const Aquatic& other);
	Aquatic& operator=(const Aquatic& other);
	Dinosaur* Clone()const;
};