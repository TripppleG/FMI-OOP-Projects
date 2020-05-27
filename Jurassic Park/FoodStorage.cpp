#include "FoodStorage.h"

FoodStorage::FoodStorage()
{
	meat = 0;
	fish = 0;
	grass = 0; 
}

FoodStorage::FoodStorage(int meat, int fish, int grass)
{
	this->meat = meat;
	this->fish = fish;
	this->grass = grass;
}

FoodStorage& FoodStorage::operator-=(const FoodStorage& foodStorage)
{
	meat -= foodStorage.meat;
	fish -= foodStorage.fish;
	grass -= foodStorage.grass;
	return *this;
}

bool operator<(const FoodStorage& f1, const FoodStorage& f2)
{
	if (f1.fish < f2.fish || f1.grass < f2.grass || f1.meat < f2.meat)
	{
		return true;
	}
	return false;
}

FoodStorage& operator-(const FoodStorage& f1, const FoodStorage& f2)
{
	FoodStorage result(f1);
	result -= f2;
	return result;
}

std::ostream& operator<<(std::ostream& os, const FoodStorage& foodStorage)
{
	return os << "Fish: " << foodStorage.fish << "\nGrass: " << foodStorage.grass << "\nMeat: " << foodStorage.meat;
}

std::istream& operator>>(std::istream& is, FoodStorage& foodStorage)
{
	char* temp = new char[10];
	is.ignore(6);
	is.getline(temp, 10);
	foodStorage.fish = atoi(temp);

	is.ignore(7);
	is.getline(temp, 10);
	foodStorage.grass = atoi(temp);

	is.ignore(6);
	is.getline(temp, 10);
	foodStorage.meat = atoi(temp);
	delete[] temp;
	return is;
}