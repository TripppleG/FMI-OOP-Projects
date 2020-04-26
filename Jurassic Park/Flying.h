#pragma once
#include "Dinosaur.h"

class Flying : public Dinosaur
{
private:
	void SetCategory();
	void SetFood();
public:
	Flying() : Dinosaur() { SetCategory(); SetFood(); }
	Flying(const char* name, const char sex, const char* era, const char* species);
	Flying(const Flying& other);
	Flying& operator=(const Flying& other);
	Dinosaur* Clone() const;
};