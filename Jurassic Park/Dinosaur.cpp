 #include "Dinosaur.h"
#include <iomanip>

void Dinosaur::SetName(const char* name)
{
	if (!name)
	{
		throw std::invalid_argument("Null pointer passed as argument!");
	}
	int length = strlen(name);
	if (length == 0)
	{
		throw std::invalid_argument("Name can't be empty");
	}
	for (int i = 0; i < length; i++)
	{
		if ((tolower(name[i]) < 'a' || tolower(name[i]) > 'z') && name[i] != ' ')
		{
			throw std::invalid_argument("Name can't contain non-letter characters!");
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
	if (!species)
	{
		throw std::invalid_argument("Null pointer passed as argument!");
	}
	int length = strlen(species);
	if (length == 0)
	{
		throw std::invalid_argument("Species can't be empty");
	}
	for (int i = 0; i < length; i++)
	{
		if ((tolower(species[i]) < 'a' || tolower(species[i]) > 'z') && species[i] != ' ')
		{
			throw std::invalid_argument("Species can't contain non-letter characters");
		}
	}
	this->species = new char[length + 1];
	strcpy_s(this->species, length + 1, species);
}

void Dinosaur::SetCategory(const Category category)
{
	this->category = category;
}

void Dinosaur::SetFood()
{
	if (category == Category::Aquatic)
	{
		food = Food::Fish;
	}
	else if (category == Category::Carnivorous)
	{
		food = Food::Meat;
	}
	else if (category == Category::Flying)
	{
		srand((unsigned)time(0));
		if (rand()%5 == 5)
		{
			food = Food::Fish;
		}
		else
		{
			food = Food::Meat;
		}
	}
	else if (category == Category::Herbivores)
	{
		food = Food::Grass;
	}
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

Dinosaur::Dinosaur()
{
	name = nullptr; sex = Sex::InvalidSex; era = Era::InvalidEra; species = nullptr; category = Category::InvalidCategory, food = Food::InvalidFood;
}

Dinosaur::Dinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category)
{
	SetName(name);
	SetSex(sex);
	SetEra(era);
	SetSpecies(species);
	SetCategory(category);
	SetFood();
}

Dinosaur::Dinosaur(const Dinosaur& other)
{
	CopyFrom(other);
}

const Dinosaur& Dinosaur::operator=(const Dinosaur& other)
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

std::ostream& operator<<(std::ostream& os, const Dinosaur& dinosaur)
{
	os << std::left << "	" << std::setw(30) << dinosaur.name << "| " << std::setw(7);
	switch ((int)dinosaur.sex)
	{
	case 1:
		os << "Male";
		break;
	case 2:
		os << "Female";
	}
	os << "| " << std::setw(11);
	switch ((int)dinosaur.era)
	{
	case 1:
		os << "Triassic";
		break;
	case 2:
		os << "Cretaceous";
		break;
	case 3:
		os << "Jurassic";
	}
	os << "| " << std::setw(24) <<  dinosaur.species << "| " << std::setw(11);
	switch ((int)dinosaur.category)
	{
	case 1:
		os << "Aquatic";
		break;
	case 2:
		os << "Carnivorous";
		break;
	case 3:
		os << "Flying";
		break;
	case 4:
		os << "Herbivores";
	} 
	os << "| ";
	switch ((int)dinosaur.food)
	{
	case 1:
		os << "Meat";
		break;
	case 2:
		os << "Grass";
		break;
	case 3:
		os << "Fish";
	}
	return os;
}

std::istream& operator>>(std::istream& is, Dinosaur& dinosaur)
{
	char* temp = new char[30];
	is.getline(temp, 30, '|');
	int length = strlen(temp);
	for (int i = 0; i < length; i++)
	{
		if ((temp[i] == temp[i + 1] && temp[i] == ' ') || i == length - 1)
		{
			temp[i] = '\0';
			break;
		}
	}
	dinosaur.SetName(temp);
	is.ignore();

	is.getline(temp, 10, ' ');
	if (!strcmp(temp, "Male"))
	{
		dinosaur.SetSex(Sex::Male);
	}
	else
	{
		dinosaur.SetSex(Sex::Female);
	}
	is.ignore(5, '|');
	is.ignore();

	is.getline(temp, 12, ' ');
	if (!strcmp(temp, "Cretaceous"))
	{
		dinosaur.SetEra(Era::Cretaceous);
	}
	else if (!strcmp(temp, "Jurassic"))
	{
		dinosaur.SetEra(Era::Jurassic);
	}
	else
	{
		dinosaur.SetEra(Era::Triassic);
	}
	is.ignore(10, '|');
	is.ignore();

	is.getline(temp, 30, '|');
	length = strlen(temp);
	for (int i = 0; i < length; i++)
	{
		if ((temp[i] == temp[i + 1] && temp[i] == ' ') || i == length - 1)
		{
			temp[i] = '\0';
			break;
		}
	}
	dinosaur.SetSpecies(temp);
	is.ignore();

	is.getline(temp, 12, ' ');
	if (!strcmp(temp, "Aquatic"))
	{
		dinosaur.SetCategory(Category::Aquatic);
	}
	else if (!strcmp(temp, "Carnivorous"))
	{
		dinosaur.SetCategory(Category::Carnivorous);
	}
	else if (!strcmp(temp, "Flying"))
	{
		dinosaur.SetCategory(Category::Flying);
	}
	else
	{
		dinosaur.SetCategory(Category::Herbivores);
	}
	is.ignore(10, '|');
	is.ignore();

	is.getline(temp, 6);
	if (!strcmp(temp, "Fish"))
	{
		dinosaur.food = Food::Fish;
	}
	else if (!strcmp(temp, "Grass"))
	{
		dinosaur.food = Food::Grass;
	}
	else
	{
		dinosaur.food = Food::Meat;
	}
	delete[] temp;
	return is;
}

bool operator==(const Dinosaur& d1, const Dinosaur& d2)
{
	return !strcmp(d1.name, d2.name) && d1.sex == d2.sex && d1.era == d2.era && d1.category == d2.category && !strcmp(d1.species, d1.species) && d1.food == d2.food;
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