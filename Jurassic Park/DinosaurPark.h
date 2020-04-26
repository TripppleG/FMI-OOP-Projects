#pragma once
#include "Cage.h"

class DinosaurPark
{
	Cage* cages;
	int numberOfCages;
	int staffCount;
	unsigned food;

	void CreateCage(const char* size, const char* climate, const char* eraOfDinosaurs, const char* dinosaurCatergory);
	void AddDinosaur(const char* name, const char sex, const char* era, const char* species);
	void RemoveDinosaur(const char* name);
	void SaveToFile(const char* fileName);
};