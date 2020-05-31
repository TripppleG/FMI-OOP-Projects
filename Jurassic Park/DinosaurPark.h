#pragma once
#include "Cage.h"
#include "FoodStorage.h"

class DinosaurPark
{
	Cage* cages;
	unsigned numberOfCages;
	unsigned maxNumberOfCages;
	unsigned staffCount;
	FoodStorage foodAvailable;
	FoodStorage foodRequired;

	void Resize();
	void CopyFrom(const DinosaurPark& other);
	void Free();
public:
	DinosaurPark();
	DinosaurPark(const DinosaurPark& other);
	DinosaurPark& operator=(const DinosaurPark& other);
	~DinosaurPark();
	friend std::ostream& operator<<(std::ostream& os, const DinosaurPark& park);
	friend std::istream& operator>>(std::istream& is, DinosaurPark& park);

	void CreateCage(const Size size, const Climate climate);
	void CreateCage(const Cage& cage);

	short AddDinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category);
	short AddDinosaur(const Dinosaur& dinosaur);

	bool RemoveDinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category);
	bool RemoveDinosaur(const Dinosaur& dinosaur);

	void RefillStorage();
	void FeedTheDinosaurs();

	const Cage* GetCages()const;
	const unsigned GetNumberOfCages()const;
	const unsigned GetMaxNumberOfCages()const;
	const unsigned GetStaffCount()const;
	const FoodStorage GetFoodRequired()const;
	const FoodStorage GetFoodAvailable()const;
};