#include "Cage.h"

void Cage::SetSize(const Size size)
{
	this->size = size;
}

void Cage::SetClimate(const Climate climate)
{
	this->climate = climate;
}

void Cage::SetEraOfDinosaurs(const Era eraOfDinosaurs)
{
	this->eraOfDinosaurs = eraOfDinosaurs;
}

void Cage::SetCapacity()
{
	if (size == Size::Small)
	{
		capacity = 1;
	}
	else if (size == Size::Medium)
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

	SetSize(other.size);
	SetClimate(other.climate);
	SetEraOfDinosaurs(other.eraOfDinosaurs);
	SetCapacity();
	numberOfDinosaurs = other.numberOfDinosaurs;
	dinosaurs = new Dinosaur*[other.capacity];
	for (int i = 0; i < numberOfDinosaurs; i++)
	{
		dinosaurs[i] = other.dinosaurs[i]->Clone();
	}
}

void Cage::Free()
{
	for (int i = 0; i < numberOfDinosaurs; i++)
	{
		delete dinosaurs[i];
	}
	delete[] dinosaurs;
}

Cage::Cage(const Size size, const Climate climate, const Era eraOfDinosaurs)
{
	SetSize(size);
	SetClimate(climate);
	SetEraOfDinosaurs(eraOfDinosaurs);
	SetCapacity();
	dinosaurs = new Dinosaur * [capacity];
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

bool Cage::IsEmpty()const
{
	return numberOfDinosaurs == 0;
}

bool Cage::IsFull()const
{
	return numberOfDinosaurs == capacity;
}

const Size Cage::GetSize() const
{
	return size;
}

const Climate Cage::GetClimate() const
{
	return climate;
}

const Era Cage::GetEraOfDinosaurs() const
{
	return eraOfDinosaurs;
}


std::ostream& operator<<(std::ostream& os, const Cage& cage)
{
	for (int i = 0; i < cage.numberOfDinosaurs; i++)
	{
		os << cage.dinosaurs[i] << '\n';
	}
	return os;
}

std::istream& operator>>(std::istream& is, Cage& cage)
{
	
	return is;
}