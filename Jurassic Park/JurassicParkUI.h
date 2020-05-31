#pragma once
#include "DinosaurPark.h"
#include <fstream>

const char FILE_NAME[] = "ParkInfo.txt";

class JurrasicParkUI
{
	DinosaurPark park;

	const char* EnterName()const;
	const Sex EnterSex()const;
	const Era EnterEra()const;
	const char* EnterSpecies()const;
	const Category EnterCategory()const;

	const Size EnterSize()const;
	const Climate EnterClimate()const;
	const Climate CategoryToClimate(const Category category)const;
	const bool AreDinosaursHungry()const;

	void AddDinosaur();
	void RemoveDinosaur();
	void CreateCage();
	void RefillTheStorage();

	void LoadFromFile(const char* filename);
	void SaveToFile(const char* filename)const;
public:
	void Run();
};