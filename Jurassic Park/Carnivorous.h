#pragma once
#include "Dinosaur.h"

class Carnivorous: public Dinosaur
{
private:
	void SetCategory();
	void SetFood();
public:
	Carnivorous(const char* name, const char sex, const char* era, const char* species);
	Carnivorous(const Carnivorous& other);
	Carnivorous& operator=(const Carnivorous& other);
	Dinosaur* Clone() const;
};