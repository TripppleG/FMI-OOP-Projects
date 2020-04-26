#pragma once
#include "Aquatic.h"
#include "Carnivorous.h"
#include "Flying.h"
#include "Herbivores.h"

class Cage
{
	Dinosaur* dinosaurs;
	char* size;
	char* climate;
	char* eraOfDinosaurs;
	int capacity;
	int dinosaursInCage;

	void SetDinosaurs(const char* dinosaurCatergory);
	void SetSize(const char* size);
	void SetClimate(const char* climate);
	void SetEraOfDinosaurs(const char* eraOfDinosaurs);
	void SetCapacity();

	void CopyFrom(const Cage& other);
	void Free();
public:
	Cage(const char* size, const char* climate, const char* eraOfDinosaurs, const char* dinosaurCatergory);
	Cage(const Cage& other);
	Cage& operator=(const Cage other);
	~Cage();
	friend std::ostream& operator<<(std::ostream os, const Cage& cage);
	friend std::istream& operator>>(std::istream is, Cage& cage);

	bool IsEmpty()const;
	bool IsFull()const;
};