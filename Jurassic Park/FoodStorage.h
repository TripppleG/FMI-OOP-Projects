#pragma once
#include <iostream>

struct FoodStorage
{
	int meat;
	int fish;
	int grass;

	FoodStorage();
	FoodStorage(int meat, int fish, int grass);

	FoodStorage& operator-=(const FoodStorage& foodStorage);
	friend FoodStorage& operator-(const FoodStorage& f1, const FoodStorage& f2);
	friend bool operator<(const FoodStorage& f1, const FoodStorage& f2);
	friend std::ostream& operator<<(std::ostream& os, const FoodStorage& foodStorage);
	friend std::istream& operator>>(std::istream& is, FoodStorage& foodStorage);
};