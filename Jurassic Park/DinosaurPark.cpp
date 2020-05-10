#include "DinosaurPark.h"

void DinosaurPark::SetName(const char* parkName)
{
	int length = strlen(parkName);
	if (length == 0)
	{
		throw std::invalid_argument("Name can't be empty");
	}
	for (int i = 0; i < length; i++)
	{
		if ((tolower(parkName[i]) < 'a' || tolower(parkName[i]) > 'z') && (parkName[i] < '0' || parkName[i] > '9'))
		{
			throw std::invalid_argument("Name can't contain non-letter/number characters!");
		}
	}
	this->parkName = new char[length + 1];
	strcpy_s(this->parkName, length + 1, parkName);
}

void DinosaurPark::Resize()
{
	maxNumberOfCages *= 2;
	Cage* temp = new Cage[maxNumberOfCages];
	for (unsigned i = 0; i < numberOfCages; i++)
	{
		temp[i] = cages[i];
	}
	delete[]cages;
	cages = temp;
}

void DinosaurPark::CopyFrom(const DinosaurPark& other)
{
	SetName(other.parkName);
	numberOfCages = other.numberOfCages;
	maxNumberOfCages = other.maxNumberOfCages;
	staffCount = other.staffCount;
	food = other.food;
	cages = new Cage[maxNumberOfCages];
	for (unsigned i = 0; i < numberOfCages; i++)
	{
		cages[i] = other.cages[i];
	}
}

void DinosaurPark::Free()
{
	delete[]cages;
	delete[]parkName;
}

DinosaurPark::DinosaurPark(const char* parkName)
{
	SetName(parkName);
	numberOfCages = 3;
	cages = new Cage[3];
	maxNumberOfCages = 4;
	staffCount = 0;
	food = 0;
}

DinosaurPark::DinosaurPark(const DinosaurPark& other)
{
	CopyFrom(other);
}

DinosaurPark& DinosaurPark::operator=(const DinosaurPark& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

DinosaurPark::~DinosaurPark()
{
	Free();
}

void DinosaurPark::CreateCage(const Size size, const Climate climate, const Era eraOfDinosaurs)
{
	if (numberOfCages == maxNumberOfCages)
	{
		Resize();
	}
	cages[numberOfCages] = Cage(size, climate, eraOfDinosaurs);
	numberOfCages++;
}

void DinosaurPark::AddDinosaur(const char* name, const char sex, const char* era, const char* species)
{
}

void DinosaurPark::RemoveDinosaur(const char* name)
{

}

void DinosaurPark::SaveToFile(const char* fileName)
{

}