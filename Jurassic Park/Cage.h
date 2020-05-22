#pragma once
#include "Dinosaur.h"

class Cage
{
private:
	Dinosaur* dinosaurs;
	Size size;
	Climate climate;
	Era eraOfDinosaurs;
	unsigned capacity;
	unsigned numberOfDinosaurs;

	void SetSize(const Size size);
	void SetClimate(const Climate climate);
	void SetEraOfDinosaurs(const Era eraOfDinosaurs);
	void SetCapacity();

	bool IsDinosaurEligible(const Dinosaur& dinosaur);
	void CopyFrom(const Cage& other);
	void Free();
public:
	Cage() { dinosaurs = nullptr; size = Size::InvalidSize; climate = Climate::InvalidClimate; eraOfDinosaurs = Era::InvalidEra; capacity = 0; numberOfDinosaurs = 0; }
	Cage(const Size size, const Climate climate);
	Cage(const Cage& other);
	Cage& operator=(const Cage& other);
	~Cage();
	friend std::ostream& operator<<(std::ostream& os, const Cage& cage);
	friend std::istream& operator>>(std::istream& is, Cage& cage);

	bool IsEmpty()const;
	bool IsFull()const;
	const Size GetSize()const;
	const Climate GetClimate()const;
	const Era GetEraOfDinosaurs()const;

	int AddDinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category);
	int AddDinosaur(const Dinosaur& dinosaur);

	bool RemoveDinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category);
	bool RemoveDinosaur(const Dinosaur& dinosaur);
};