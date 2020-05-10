#include "Dinosaur.h"

void Dinosaur::SetName(const char* name)
{
	int length = strlen(name);
	if (length == 0)
	{
		throw std::invalid_argument("Name can't be empty");
	}
	for (int i = 0; i < length; i++)
	{
		if (tolower(name[i]) < 'a' || tolower(name[i]) > 'z')
		{
			throw std::invalid_argument("Name can't contain non-letter characters!s");
		}
	}
	this->name = new char[length + 1];
	strcpy_s(this->name, length + 1, name);
}

void Dinosaur::SetSex(const Sex sex)
{
	this->sex = sex;
}

void Dinosaur::SetEra(const Era era)
{
	this->era = era;
}

void Dinosaur::SetSpecies(const char* species)
{
	int length = strlen(species);
	if (length == 0)
	{
		throw std::invalid_argument("Species can't be empty");
	}
	for (int i = 0; i < length; i++)
	{
		if (tolower(species[i]) < 'a' || tolower(species[i]) > 'z')
		{
			throw std::invalid_argument("Species can't contain non-letter characters");
		}
	}
	this->species = new char[length + 1];
	strcpy_s(this->species, length + 1, species);
}

void Dinosaur::CopyFrom(const Dinosaur& other)
{
	SetName(other.name);
	SetSex(other.sex);
	SetEra(other.era);
	SetSpecies(other.species);
	category = other.category;
	food = other.food;
}

void Dinosaur::Free()
{
	delete[] name;
	delete[] species;
}

Dinosaur::Dinosaur(const char* name, const Sex sex, const Era era, const char* species)
{
	SetName(name);
	SetSex(sex);
	SetEra(era);
	SetSpecies(species);
}

Dinosaur::Dinosaur(const Dinosaur& other)
{
	CopyFrom(other);
}

Dinosaur& Dinosaur::operator=(const Dinosaur& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

Dinosaur::~Dinosaur()
{
	Free();
}

const char* Dinosaur::GetName() const
{
	return name;
}

const Sex Dinosaur::GetSex() const
{
	return sex;
}

const Era Dinosaur::GetEra() const
{
	return era;
}

const char* Dinosaur::GetSpecies() const
{
	return species;
}

const Category Dinosaur::GetCategory() const
{
	return category;
}

const Food Dinosaur::GetFood() const
{
	return food;
}

//std::ostream& operator<<(std::ostream& os, const Dinosaur& dinosaur)
//{
//	return os << dinosaur.name << '\0' << dinosaur.sex << '\0' << dinosaur.era << '\0' << dinosaur.category << '\0' << dinosaur.species << '\0' << dinosaur.food;
//}
//
//std::istream& operator>>(std::istream& is, Dinosaur& dinosaur)
//{
//	 is.getline(dinosaur.name, 2, '\0');
//	 is >> dinosaur.sex;
//	 return is;
//}
