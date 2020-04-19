#pragma once
#include "Dinosaur.h"
#include "Aquatic.h"
class Cage
{
	Dinosaur* dinosaurs;
	char* size;
	char* climate;
	char* eraOfDinosaurs;
	int capacity;
	int numberOfDinosaurs;

	void SetSize(const char* size);
	void SetClimate(const char* climate);
	void SetEraOfDinosaurs(const char* eraOfDinosaurs);
	void SetCapacity();

	void CopyFrom(const Cage& other);
	void Free();
public:
	Cage(const char* size, const char* climate, const char* eraOfDinosaurs);
	Cage(const Cage& other);
	Cage& operator=(const Cage other);
	~Cage();

	void AddDinosaur();
	void RemoveDinosaurs();
	void IsEmpty();
	void IsFull();
};