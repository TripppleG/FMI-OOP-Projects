#include "Cage.h"

void Cage::SetSize(const char* size)
{
	if (strcmp(size, "Small") && strcmp(size, "Medium") && strcmp(size, "Large"))
	{
		throw std::invalid_argument("The size ot the cage must be Small, Medium or Large");
	}
	int length = strlen(size);
	this->size = new char[length + 1];
	strcpy_s(this->size, length, size);
}

void Cage::SetClimate(const char* climate)
{
	if (strcmp(climate, "Terrestrial") && strcmp(climate, "Aerial") && strcmp(climate, "Aqueous"))
	{
		throw std::invalid_argument("The size ot the cage must be Terrestrial, Aerial or Aqueous");
	}
	int length = strlen(climate);
	this->climate = new char[length + 1];
	strcpy_s(this->climate, length, climate);
}

void Cage::SetEraOfDinosaurs(const char* eraOfDinosaurs)
{
	if (strcmp(eraOfDinosaurs, "Triassic") && strcmp(eraOfDinosaurs, "Cretaceous") && strcmp(eraOfDinosaurs, "Jurassic"))
	{
		throw std::invalid_argument("Era must be Triassic, Cretaceous or Jurassic");
	}
	int length = strlen(eraOfDinosaurs);
	this->eraOfDinosaurs = new char[length + 1];
	strcpy_s(this->eraOfDinosaurs, length + 1, eraOfDinosaurs);
}

void Cage::SetCapacity()
{
	if (!strcmp(size, "Small"))
	{
		capacity = 1;
	}
	else if (!strcmp(size, "Medium"))
	{
		capacity = 3;
	}
	else
	{
		capacity = 10;
	}
}

void Cage::CopyFrom(const Cage& other)
{
	// TODO: FIX THIS METHOD
	SetSize(other.size);
	SetClimate(other.climate);
	SetEraOfDinosaurs(other.eraOfDinosaurs);
	SetCapacity();
	numberOfDinosaurs = other.numberOfDinosaurs;
	dinosaurs = new Aquatic[capacity];
	for (int i = 0; i < other.numberOfDinosaurs; i++)
	{
		dinosaurs[i] = other.dinosaurs[i];
	}
}

void Cage::Free()
{
	delete[] dinosaurs;
	delete[] size;
	delete[] climate;
	delete[] eraOfDinosaurs;
}

Cage::Cage(const char* size, const char* climate, const char* eraOfDinosaurs)
{
	SetSize(size);
	SetClimate(climate);
	SetEraOfDinosaurs(eraOfDinosaurs);
	SetCapacity();
	numberOfDinosaurs = 0;

}

Cage::Cage(const Cage& other)
{
	CopyFrom(other);
}

Cage& Cage::operator=(const Cage other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

Cage::~Cage()
{
	Free();
}
