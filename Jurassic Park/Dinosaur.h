#pragma once
#include <iostream>
#include "Enums.h"

class Dinosaur
{
	void SetName(const char* name);
	void SetSex(const Sex sex);
	void SetEra(const Era era);
	void SetSpecies(const char* species);

	void CopyFrom(const Dinosaur& other);
	void Free();
protected:
	char* name;
	Sex sex;
	Era era;
	char* species;
	Category category;
	Food food;
	//ID    |		Name		| Sex |	Era | Category | Species | Food
public:
	Dinosaur() { name = nullptr; sex = Sex::InvalidSex; era = Era::InvalidEra; species = nullptr; }
	Dinosaur(const char* name, const Sex sex, const Era era, const char* species);
	Dinosaur(const Dinosaur& other);
	Dinosaur& operator=(const Dinosaur& other);
	~Dinosaur();
	friend std::ostream& operator<<(std::ostream& os, const Dinosaur& dinosaur);
	friend std::istream& operator>>(std::istream& is, Dinosaur& dinosaur);

	const char* GetName() const;
	const Sex GetSex() const;
	const Era GetEra() const;
	const char* GetSpecies() const;
	const Category GetCategory() const;
	const Food GetFood() const;
	virtual Dinosaur* Clone()const = 0;
};