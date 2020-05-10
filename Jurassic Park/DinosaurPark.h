#pragma once
#include "Cage.h"

class DinosaurPark
{
	Cage* cages;
	char* parkName;
	unsigned numberOfCages;
	unsigned maxNumberOfCages;
	unsigned staffCount;
	unsigned food;

	void SetName(const char* parkName);

	void Resize();
	void CopyFrom(const DinosaurPark& other);
	void Free();
public:
	DinosaurPark(const char* parkName);
	DinosaurPark(const DinosaurPark& other);
	DinosaurPark& operator=(const DinosaurPark& other);
	~DinosaurPark();

	void CreateCage(const Size size, const Climate climate, const Era eraOfDinosaurs);
	void AddDinosaur(const char* name, const char sex, const char* era, const char* species);
	void RemoveDinosaur(const char* name);
	void SaveToFile(const char* fileName);
};