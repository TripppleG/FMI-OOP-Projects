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
			throw std::invalid_argument("Name can't contain non-characters");
		}
	}
	this->name = new char[length + 1];
	strcpy_s(this->name, length + 1, name);
}

void Dinosaur::SetSex(const char sex)
{
	if (sex != 'M' && sex != 'F')
	{
		throw std::invalid_argument("Sex must be either M or F");
	}
	this->sex = sex;
}

void Dinosaur::SetEra(const char* era)
{
	if (strcmp(era, "Triassic") && strcmp(era, "Cretaceous") && strcmp(era, "Jurassic"))
	{
		throw std::invalid_argument("Era must be Triassic, Cretaceous or Jurassic");
	}
	int length = strlen(era);
	this->era = new char[length + 1];
	strcpy_s(this->era, length + 1, era);
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
			throw std::invalid_argument("Species can't contain non-characters");
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
}

void Dinosaur::Free()
{
	delete[] name;
	delete[] era;
	delete[] category;
	delete[] species;
	delete[] food;
}

Dinosaur::Dinosaur(const char* name, const char sex, const char* era, const char* species)
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

const char Dinosaur::GetSex() const
{
	return sex;
}

const char* Dinosaur::GetEra() const
{
	return era;
}

const char* Dinosaur::GetSpecies() const
{
	return species;
}

const char* Dinosaur::GetCategory() const
{
	return category;
}

const char* Dinosaur::GetFood() const
{
	return food;
}

std::ostream& operator<<(std::ostream& out, const Dinosaur& dinosaur)
{
	return out << dinosaur.name << ' ' << dinosaur.sex << ' ' << dinosaur.era << ' ' << dinosaur.category << ' ' << dinosaur.species << ' ' << dinosaur.food;
}

std::istream& operator>>(std::istream& in, Dinosaur& dinosaur)
{
	
	in.getline(dinosaur.name, 10000);
	in >> dinosaur.sex;
	in.getline(dinosaur.era, 10000);
	in.getline(dinosaur.category, 10000);
	in.getline(dinosaur.species, 10000);
	in.getline(dinosaur.food, 10000);
	return in;
}
