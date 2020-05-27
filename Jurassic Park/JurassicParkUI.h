#pragma once
#include "DinosaurPark.h"
#include <fstream>

const char FILE_NAME[] = "ParkInfoTest.txt";

class JurrasicPark
{
	DinosaurPark park;

	const char* EnterName()const;
	const Sex EnterSex()const;
	const Era EnterEra()const;
	const char* EnterSpecies()const;
	const Category EnterCategory()const;

	const Climate CategoryToClimate(const Category category);
	const Size EnterSize()const;
	const Climate EnterClimate()const;

	void LoadFromFile(const char* filename);
	void SaveToFile(const char* filename);
public:
	JurrasicPark();
};