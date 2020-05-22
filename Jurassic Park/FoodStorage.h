#pragma once
#include <iostream>

struct FoodStorage
{
	int meat;
	int fish;
	int grass;

	FoodStorage() { meat = 0; fish = 0; grass = 0; }
	FoodStorage(int _meat, int _fish, int _grass) :meat(_meat), grass(_grass), fish(_fish) {}

	FoodStorage& operator-=(const FoodStorage& f);
	friend bool operator<(const FoodStorage& f1, const FoodStorage& f2);
	friend std::ostream& operator<<(std::ostream& os, const FoodStorage& f);
	friend std::istream& operator>>(std::istream& is, FoodStorage& f);
};