#pragma once
#include "Dinosaur.h"

class Herbivores : public Dinosaur
{
private:
	void SetCategory();
	void SetFood();
public:
	Herbivores(const char* name, const char sex, const char* era, const char* species);
	Herbivores(const Herbivores& other);
	Herbivores& operator=(const Herbivores& other);
	Dinosaur* Clone() const;
};