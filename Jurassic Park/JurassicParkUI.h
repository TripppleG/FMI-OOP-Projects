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

	const Climate CategoryToClimate(const Category category)const;
	const Size EnterSize()const;
	const Climate EnterClimate()const;

	void LoadFromFile(const char* filename);
	void SaveToFile(const char* filename)const;
public:
	JurrasicParkUI();
	void Run();
};