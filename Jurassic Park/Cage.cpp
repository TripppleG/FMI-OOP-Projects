#include "Cage.h"
#include <iomanip>

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

bool Cage::IsDinosaurEligible(const Dinosaur& dinosaur)
{
	if ((climate == Climate::Aerial && dinosaur.GetCategory() == Category::Flying) ||
		(climate == Climate::Aqueous && dinosaur.GetCategory() == Category::Aquatic) ||
		(climate == Climate::Terrestrial && (dinosaur.GetCategory() == Category::Carnivorous || dinosaur.GetCategory() == Category::Herbivores)))
	{
		if (IsFull())
		{
			return false;
		}
		else if (IsEmpty())
		{
			eraOfDinosaurs = dinosaur.GetEra();
			return true;
		}
		else
		{
			return eraOfDinosaurs == dinosaur.GetEra();
		}
	}
	else
	{
		return false;
	}
}

void Cage::CopyFrom(const Cage& other)
{
	SetSize(other.size);
	SetClimate(other.climate);
	SetEraOfDinosaurs(other.eraOfDinosaurs);
	SetCapacity();
	numberOfDinosaurs = other.numberOfDinosaurs;
	dinosaurs = new Dinosaur[other.capacity];
	for (unsigned i = 0; i < numberOfDinosaurs; i++)
	{
		dinosaurs[i] = other.dinosaurs[i];
	}
}

void Cage::Free()
{
	delete[] dinosaurs;
}

Cage::Cage()
{
	dinosaurs = nullptr; size = Size::InvalidSize; climate = Climate::InvalidClimate; eraOfDinosaurs = Era::InvalidEra; capacity = 0; numberOfDinosaurs = 0; 
}

Cage::Cage(const Size size, const Climate climate)
{
	SetSize(size);
	SetClimate(climate);
	SetCapacity();
	dinosaurs = new Dinosaur[capacity];
	numberOfDinosaurs = 0;
	eraOfDinosaurs = Era::InvalidEra;
}

Cage::Cage(const Cage& other)
{
	CopyFrom(other);
}

Cage& Cage::operator=(const Cage& other)
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


short Cage::AddDinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category)
{
	const Dinosaur temp(name, sex, era, species, category);
	return AddDinosaur(temp);
}

short Cage::AddDinosaur(const Dinosaur& dinosaur)
{
	for (unsigned i = 0; i < numberOfDinosaurs; i++)
	{
		if (dinosaurs[i] == dinosaur)
		{
			return -1;
		}
	}
	if (IsDinosaurEligible(dinosaur))
	{
		dinosaurs[numberOfDinosaurs] = dinosaur;
		numberOfDinosaurs++;
		return 1;
	}
	return 0;
}

bool Cage::RemoveDinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category)
{
	const Dinosaur temp(name, sex, era, species, category);
	return RemoveDinosaur(temp);
}

bool Cage::RemoveDinosaur(const Dinosaur& dinosaur)
{
	if (IsEmpty())
	{
		return false;
	}
	for (unsigned i = 0; i < numberOfDinosaurs; i++)
	{
		if (dinosaurs[i] == dinosaur)
		{
			for (unsigned j = i; j < numberOfDinosaurs - 1; j++)
			{
				dinosaurs[j] = dinosaurs[j + 1];
			}
			numberOfDinosaurs--;
			if (IsEmpty())
			{
				*this = Cage(size, climate);
			}
			return true;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const Cage& cage)
{
	os << std::setfill(' ');
	os << std::left << "	" << "Size: ";
	os << std::setw(7);
	switch ((int)cage.size)
	{
	case 1:
		os << "Small";
		break;
	case 2:
		os << "Medium";
		break;
	case 3:
		os << "Large";
	}
	os << "| Climate: " << std::setw(12);
	switch ((int)cage.climate)
	{
	case 1:
		os << "Terrestrial";
		break;
	case 2:
		os << "Aerial";
		break;
	case 3:
		os << "Aqueous";
	}
	os << "| Era: ";
	switch ((int)cage.eraOfDinosaurs)
	{
	case 1:
		os << "Triassic";
		break;
	case 2:
		os << "Cretaceous";
		break;
	case 3:
		os << "Jurassic";
		break;
	default: 
		os << "NULL";
	}
	os << std::endl;
	if (cage.IsEmpty())
	{
		os << "	Empty cage";
	}
	else
	{
		os << "	Dinosaurs in cage: " << cage.numberOfDinosaurs << std::endl;
		os << "	" << std::left << std::setw(30) << "Name" << "| " << std::setw(7) << "Sex" << "| " << std::setw(11) << "Era" << "| " << std::setw(24) << "Species" << "| " << std::setw(11) << "Category" << "| " << "Food" << std::endl;
		for (unsigned i = 0; i < cage.numberOfDinosaurs; i++)
		{
			os << cage.dinosaurs[i] << std::endl;
		}
	}
	os << std::endl;
	os << std::setw(107) << std::setfill('-') << "" << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Cage& cage)
{
	char* temp = new char[30];
	is.ignore(7);
	is.getline(temp, 7, ' ');
	if (!strcmp(temp, "Small"))
	{
		cage.SetSize(Size::Small);
	}
	else if (!strcmp(temp, "Medium"))
	{
		cage.SetSize(Size::Medium);
	}
	else
	{
		cage.SetSize(Size::Large);
	}
	cage.SetCapacity();

	is.ignore(10, '|');
	is.ignore(10);
	is.getline(temp, 12, ' ');
	if (!strcmp(temp, "Aerial"))
	{
		cage.SetClimate(Climate::Aerial);
	}
	else if (!strcmp(temp, "Aqueous"))
	{
		cage.SetClimate(Climate::Aqueous);
	}
	else
	{
		cage.SetClimate(Climate::Terrestrial);
	}

	is.ignore(10, '|');
	is.ignore(6);
	is.getline(temp, 11);
	if (!strcmp(temp, "Triassic"))
	{
		cage.SetEraOfDinosaurs(Era::Triassic);
	}
	else if (!strcmp(temp, "Jurassic"))
	{
		cage.SetEraOfDinosaurs(Era::Jurassic);
	}
	else if(!strcmp(temp, "Cretaceous"))
	{
		cage.SetEraOfDinosaurs(Era::Cretaceous);
	}
	else
	{
		cage.SetEraOfDinosaurs(Era::InvalidEra);
	}

	is.ignore();
	is.getline(temp, 20, ':');
	delete[] cage.dinosaurs;
	cage.dinosaurs = new Dinosaur[cage.capacity];
	if (strcmp(temp, "Empty cage") != 0)
	{
		is.getline(temp, 12);
		is.ignore(110, '\n');
		cage.numberOfDinosaurs = atoi(temp);
		for (unsigned i = 0; i < cage.numberOfDinosaurs; i++)
		{
			is.ignore();
			is >> cage.dinosaurs[i];
		}
	}
	else
	{
		cage.numberOfDinosaurs = 0;
	}

	is.ignore(110, '\n');
	delete[] temp;
	return is;
}

const Dinosaur* Cage::GetDinosaurs() const
{
	return dinosaurs;
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

const unsigned Cage::GetCapacity() const
{
	return capacity;
}

const unsigned Cage::GetNumberOfDinosaurs() const
{
	return numberOfDinosaurs;
}