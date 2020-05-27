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
	Cage();
	Cage(const Size size, const Climate climate);
	Cage(const Cage& other);
	Cage& operator=(const Cage& other);
	~Cage();
	friend std::ostream& operator<<(std::ostream& os, const Cage& cage);
	friend std::istream& operator>>(std::istream& is, Cage& cage);

	bool IsEmpty()const;
	bool IsFull()const;

	short AddDinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category);
	short AddDinosaur(const Dinosaur& dinosaur);

	bool RemoveDinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category);
	bool RemoveDinosaur(const Dinosaur& dinosaur);

	const Size GetSize()const;
	const Climate GetClimate()const;
	const Era GetEraOfDinosaurs()const;
	const unsigned GetCapacity()const;
	const unsigned GetNumberOfDinosaurs()const;
};