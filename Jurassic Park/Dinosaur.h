#pragma once
#include <iostream>
#include "Enums.h"

class Dinosaur
{
	void SetName(const char* name);
	void SetSex(const Sex sex);
	void SetEra(const Era era);
	void SetSpecies(const char* species);
	void SetCategory(const Category category);
	void SetFood();

	void CopyFrom(const Dinosaur& other);
	void Free();

	char* name;
	Sex sex;
	Era era;
	char* species;
	Category category;
	Food food;
public:
	Dinosaur() { name = nullptr; sex = Sex::InvalidSex; era = Era::InvalidEra; species = nullptr; category = Category::InvalidCategory, food = Food::InvalidFood; }
	Dinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category);
	Dinosaur(const Dinosaur& other);
	Dinosaur& operator=(const Dinosaur& other);
	~Dinosaur();
	friend std::ostream& operator<<(std::ostream& os, const Dinosaur& dinosaur);
	friend std::istream& operator>>(std::istream& is, Dinosaur& dinosaur);
	friend bool operator==(const Dinosaur& d1, const Dinosaur& d2);

	const char* GetName() const;
	const Sex GetSex() const;
	const Era GetEra() const;
	const char* GetSpecies() const;
	const Category GetCategory() const;
	const Food GetFood() const;
};