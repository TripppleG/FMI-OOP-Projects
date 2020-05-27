#include "DinosaurPark.h"
#include <iomanip>

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
	numberOfCages = other.numberOfCages;
	maxNumberOfCages = other.maxNumberOfCages;
	staffCount = other.staffCount;
	foodAvailable = other.foodAvailable;
	foodRequired = other.foodRequired;
	cages = new Cage[maxNumberOfCages];
	for (unsigned i = 0; i < numberOfCages; i++)
	{
		cages[i] = other.cages[i];
	}
}

void DinosaurPark::Free()
{
	delete[]cages;
}

DinosaurPark::DinosaurPark()
{
	numberOfCages = 3;
	maxNumberOfCages = 4;
	staffCount = numberOfCages;
	cages = new Cage[numberOfCages];
	cages[0] = Cage(Size::Medium, Climate::Aerial);
	cages[1] = Cage(Size::Medium, Climate::Aqueous);
	cages[2] = Cage(Size::Large, Climate::Terrestrial);
	foodAvailable = FoodStorage(10, 10, 10);
	foodRequired = FoodStorage(0, 0, 0);
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

std::ostream& operator<<(std::ostream& os, const DinosaurPark& park)
{
	os << "Staff count: " << park.staffCount << std::endl;
	os << "Number of cages: " << park.numberOfCages << std::endl;
	os << "Park capacity for cages: " << park.maxNumberOfCages << std::endl;
	os << "Food required to feed the dinosaurs:\n" << park.foodRequired << std::endl << std::endl;
	os << "Food available:\n" << park.foodAvailable << std::endl << std::endl;
	os << std::setfill('-') << std::setw(108) << "\n";
	
	for (unsigned i = 0; i < park.numberOfCages; i++)
	{
		os << "Cage " << i + 1 << ":" << std::endl;
		os << park.cages[i];
	}
	return os;
}

std::istream& operator>>(std::istream& is, DinosaurPark& park)
{
	char* temp = new char[11];
	is.ignore(13);
	is.getline(temp, 11);
	park.staffCount = atoi(temp);
	is.ignore(17);

	is.getline(temp, 11);
	park.numberOfCages = atoi(temp);
	is.ignore(25);

	is.getline(temp, 11);
	park.maxNumberOfCages = atoi(temp);
	is.ignore(37);

	is >> park.foodRequired;
	is.ignore(17);
	
	is >> park.foodAvailable;
	is.ignore(110, '\n');

	delete[] park.cages;
	park.cages = new Cage[park.maxNumberOfCages];
	for (unsigned i = 0; i < park.numberOfCages; i++)
	{
		is.ignore(8);
		is >> park.cages[i];
	}
	return is;
}

void DinosaurPark::CreateCage(const Size size, const Climate climate)
{
	const Cage temp(size, climate);
	CreateCage(temp);
}

void DinosaurPark::CreateCage(const Cage& cage)
{
	if (numberOfCages == maxNumberOfCages)
	{
		Resize();
	}
	cages[numberOfCages] = cage;
	numberOfCages++;
	staffCount++;
}

short DinosaurPark::AddDinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category)
{
	const Dinosaur temp(name, sex, era, species, category);
	return AddDinosaur(temp);
}

short DinosaurPark::AddDinosaur(const Dinosaur& dinosaur)
{
	for (unsigned i = 0; i < numberOfCages; i++)
	{
		short result = cages[i].AddDinosaur(dinosaur);
		if (result == -1)
		{
			return -1;
		}
		else if(result == 1)
		{
			if (dinosaur.GetFood() == Food::Fish)
			{
				foodRequired.fish++;
			}
			else if (dinosaur.GetFood() == Food::Grass)
			{
				foodRequired.grass++;
			}
			else
			{
				foodRequired.meat++;
			}
			return 1;
		}
	}
	return 0;
}

bool DinosaurPark::RemoveDinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category)
{
	const Dinosaur temp(name, sex, era, species, category);
	return RemoveDinosaur(temp);
}

bool DinosaurPark::RemoveDinosaur(const Dinosaur& dinosaur)
{
	for (unsigned i = 0; i < numberOfCages; i++)
	{
		if (cages[i].RemoveDinosaur(dinosaur))
		{
			return true;
		}
	}
	return false;
}

void DinosaurPark::RefillStorage()
{
	if (foodRequired.fish != 0)
	{
		foodAvailable.fish = 4 * foodRequired.fish;
	}
	if (foodRequired.grass != 0)
	{
		foodAvailable.grass = 4 * foodRequired.grass;
	}
	if (foodRequired.meat != 0)
	{
		foodAvailable.meat = 4 * foodRequired.meat;
	}
}

void DinosaurPark::FeedTheDinosaurs()
{
	foodAvailable -= foodRequired;
}

const unsigned DinosaurPark::GetNumberOfCages() const
{
	return numberOfCages;
}

const unsigned DinosaurPark::GetMaxNumberOfCages() const
{
	return maxNumberOfCages;
}

const unsigned DinosaurPark::GetStaffCount() const
{
	return staffCount;
}

const FoodStorage DinosaurPark::GetFoodRequired() const
{
	return foodRequired;
}

const FoodStorage DinosaurPark::GetFoodAvailable() const
{
	return foodAvailable;
}