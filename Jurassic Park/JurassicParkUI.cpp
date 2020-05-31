#include "JurassicParkUI.h"

const char* JurrasicParkUI::EnterName() const
{
	bool isCorrect = false;
	char* name = new char[30];
	do
	{
		std::cout << "Enter the name of the dinosaur:\n";
		std::cin.ignore();
		std::cin.getline(name, 30);
		try
		{
			Dinosaur d(name, Sex(-1), Era(-1), "s", Category(-1));
			isCorrect = true;
		}
		catch (const std::invalid_argument&)
		{
			std::cout << "Invalid name!\n";
		}
		std::cout << std::endl;
	} while (!isCorrect);
	return name;
}

const Sex JurrasicParkUI::EnterSex() const
{
	Sex sex;
	int choice;
	std::cout << "Choose the sex of the dinosaur:\n1) Male\n2) Female\nYour choice: ";
	std::cin >> choice;

	while (choice != 1 && choice != 2)
	{
		std::cout << std::endl;
		std::cout << "Invalid choice! Please choose again:\n1) Male\n2) Female\nYour choice: ";
		std::cin >> choice;
	}
	std::cout << std::endl;
	sex = (Sex)choice;
	return sex;
}

const Era JurrasicParkUI::EnterEra() const
{
	Era era;
	int choice;
	std::cout << "Enter the era of the dinosaur:\n1) Triassic\n2) Cretaceous\n3) Jurassic\nYour choice: ";
	std::cin >> choice;

	while (choice != 1 && choice != 2 && choice != 3)
	{
		std::cout << std::endl;
		std::cout << "Invalid choice! Please choose again:\n1) Triassic\n2) Cretaceous\n3) Jurassic\nYour choice: ";
		std::cin >> choice;
	}
	std::cout << std::endl;
	era = (Era)choice;
	return era;
}

const char* JurrasicParkUI::EnterSpecies() const
{
	bool isCorrect = false;
	char* species = new char[30];
	std::cin.ignore();
	do
	{
		std::cout << "Enter the species of the dinosaur:\n";
		std::cin.getline(species, 30);
		try
		{
			Dinosaur d("N", Sex(-1), Era(-1), species, Category(-1));
			isCorrect = true;
		}
		catch (const std::invalid_argument&)
		{
			std::cout << "Invalid Species!\n";
		}
		std::cout << std::endl;
	} while (!isCorrect);
	return species;
}

const Category JurrasicParkUI::EnterCategory() const
{
	Category category;
	int choice;
	std::cout << "Choose the category of the dinosaur:\n1) Aquatic\n2) Carnivorous\n3) Flying\n4) Herbivores\nYour choice: ";
	std::cin >> choice;

	while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
	{
		std::cout << std::endl;
		std::cout << "Invalid choice! Please choose again:\n1) Aquatic\n2) Carnivorous\n3) Flying\n4) Herbivores\nYour choice: ";
		std::cin >> choice;
	}
	category = (Category)choice;
	return category;
}

const Climate JurrasicParkUI::CategoryToClimate(const Category category) const
{
	if (category == Category::Aquatic)
	{
		return Climate::Aqueous;
	}
	else if (category == Category::Carnivorous || category == Category::Herbivores)
	{
		return Climate::Terrestrial;
	}
	else
	{
		return Climate::Aerial;
	}
}

const Size JurrasicParkUI::EnterSize() const
{
	Size size;
	int choice;
	std::cout << "Choose the size of the cage:\n1) Small\n2) Medium\n3) Large\nYour choice: ";
	std::cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3)
	{
		std::cout << std::endl;
		std::cout << "Invalid choice! Please choose again:\n1) Small\n2) Medium\n3) Large\nYour choice: ";
		std::cin >> choice;
	}
	std::cout << std::endl;
	size = (Size)choice;
	return size;
}

const Climate JurrasicParkUI::EnterClimate() const
{
	Climate climate;
	int choice;
	std::cout << "Choose the climate of the cage:\n1) Terrestrial\n2) Aerial\n3) Aqueous\nYour choice: ";
	std::cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3)
	{
		std::cout << std::endl;
		std::cout << "Invalid choice! Please choose again:\n1) Terrestrial\n2) Aerial\n3) Aqueous\nYour choice: ";
		std::cin >> choice;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	climate = (Climate)choice;
	return climate;
}

void JurrasicParkUI::LoadFromFile(const char* filename)
{
	std::ifstream myFile(filename, std::ios::in);
	if (!myFile)
	{
		throw std::runtime_error("File couldn't be open!");
	}
	if (myFile.peek() == std::ifstream::traits_type::eof()) // Checking if the file is empty
	{
		throw std::runtime_error("File is empty");
	}
	myFile >> park;
	std::cout << "File loaded successfully!" << std::endl;
}

void JurrasicParkUI::SaveToFile(const char* filename) const
{
	std::ofstream myFile(filename, std::ios::out | std::ios::trunc); // File will always open, because if it doesn't exist it will create a new one
	myFile << park;
	std::cout << "Changes saved successfully";
}

JurrasicParkUI::JurrasicParkUI() {}

void JurrasicParkUI::Run()
{
	try
	{
		LoadFromFile(FILE_NAME);
	}
	catch (const std::runtime_error&)
	{
		park = DinosaurPark();
	}
	std::cout << "Welcome to Jurrasic park! ";
	short choice;
	do
	{
		if (park.GetFoodAvailable() < park.GetFoodRequired())
		{
			std::cout << "DINOSAUR ARE STARVING! PLEASE REFILL THE FOOD STORAGE!\n";
		}
		std::cout << "Please choose what you want to do:\n1) Add dinosaur\n2) Remove dinosaur\n3) Create new cage\n4) Fill the storage\n5) Exit\nYour choice: ";
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice)
		{
		case 1:
		{
			const char* name = EnterName();
			const Sex sex = EnterSex();
			const Era era = EnterEra();
			const char* species = EnterSpecies();
			const Category category = EnterCategory();
			const short result = park.AddDinosaur(name, sex, era, species, category);
			if (result == -1)
			{
				std::cout << "Dinosaur already exists in the park!\n\n";
			}
			else if (result == 0)
			{
				std::cout << "There is no eligible empty space for the dinosaur. You must create a new cage for it to be added!\n\n";
				Size size = EnterSize();
				park.CreateCage(size, CategoryToClimate(category));
				park.AddDinosaur(name, sex, era, species, category);
			}
			else
			{
				std::cout << "Dinosaur added successfully!\n\n";
			}
			delete[] name; // Deleting the memory allocated in EnterName()
			delete[] species; // Deleting the memory allocated in EnterSpecies()
			break;
		}
		case 2:
		{
			const char* name = EnterName();
			const Sex sex = EnterSex();
			const Era era = EnterEra();
			const char* species = EnterSpecies();
			const Category category = EnterCategory();
			const bool isSuccessful = park.RemoveDinosaur(name, sex, era, species, category);
			if (isSuccessful)
			{
				std::cout << "Dinosaur removed successfully!\n\n";
			}
			else
			{
				std::cout << "There is no dinosaur with these specifications in the park!\n\n";
			}
			delete[] name; // Deleting the memory allocated in EnterName()
			delete[] species; // Deleting the memory allocated in EnterSpecies()
			break;
		}
		case 3:
		{
			const Size size = EnterSize();
			const Climate climate = EnterClimate();
			park.CreateCage(size, climate);
			std::cout << "Cage created successfully!\n\n";
			break;
		}
		case 4:
			park.RefillStorage();
			std::cout << "Food storage refilled successfully!\n\n";
			break;
		case 5:
			std::cout << "Bye!\n";
			break;
		default:
			std::cout << "Incorrect choice!\n";
		}
		park.FeedTheDinosaurs();
	} while (choice != 5);
	SaveToFile(FILE_NAME);
}
