#include "FoodStorage.h"

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

FoodStorage& FoodStorage::operator-=(const FoodStorage& f)
{
	meat -= f.meat;
	fish -= f.fish;
	grass -= f.grass;
	return *this;
}
std::ostream& operator<<(std::ostream& os, const FoodStorage& f)
{
	return os << "Fish: " << f.fish << "\nGrass: " << f.grass << "\nMeat: " << f.meat;
}

std::istream& operator>>(std::istream& is, FoodStorage& f)
{
	char* temp = new char[10];
	is.ignore(6);
	is.getline(temp, 10);
	f.fish = atoi(temp);

	is.ignore(7);
	is.getline(temp, 10);
	f.grass = atoi(temp);

	is.ignore(6);
	is.getline(temp, 10);
	f.meat = atoi(temp);
	delete[] temp;
	return is;
}