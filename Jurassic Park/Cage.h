#pragma once
#include "Aquatic.h"
#include "Carnivorous.h"
#include "Flying.h"
#include "Herbivores.h"

class Cage
{
	Dinosaur** dinosaurs;
	Size size;
	Climate climate;
	Era eraOfDinosaurs;
	int capacity;
	int numberOfDinosaurs;

	void SetSize(const Size size);
	void SetClimate(const Climate climate);
	void SetEraOfDinosaurs(const Era eraOfDinosaurs);
	void SetCapacity();

	void CopyFrom(const Cage& other);
	void Free();
public:
	Cage() { dinosaurs = nullptr; size = Size::InvalidSize; climate = Climate::InvalidClimate; eraOfDinosaurs = Era::InvalidEra; capacity = 0; numberOfDinosaurs = 0; }
	Cage(const Size size, const Climate climate, const Era eraOfDinosaurs);
	Cage(const Cage& other);
	Cage& operator=(const Cage other);
	~Cage();
	friend std::ostream& operator<<(std::ostream& os, const Cage& cage);
	friend std::istream& operator>>(std::istream& is, Cage& cage);

	bool IsEmpty()const;
	bool IsFull()const;

	const Size GetSize()const;
	const Climate GetClimate()const;
	const Era GetEraOfDinosaurs()const;
};