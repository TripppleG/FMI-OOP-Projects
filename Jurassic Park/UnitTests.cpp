#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "DinosaurPark.h"

TEST_CASE("Testing Dinosaur class")
{
	Dinosaur d("Gosho", Sex::Male, Era::Jurassic, "Brontosaur", Category::Herbivores);
	std::cout << "Test 1 - Dinosaur class\n";
	SUBCASE("Testing Copyconstructor:")
	{
		std::cout << "Test subcase: 1.1" << std::endl;
		std::cout << "Testing if two objects are equal if one is created from the other using the copyconstructor:\n";
		Dinosaur d1 = d;
		CHECK_EQ(d1, d);
	}
	SUBCASE("Testing operator=")
	{
		std::cout << "Test subcase: 1.2" << std::endl;
		std::cout << "Assigning one object to another and checking if they are equal after that: \n";
		Dinosaur d1;
		d1 = d;
		CHECK_EQ(d1, d);
	}
	SUBCASE("Testing operator==")
	{
		std::cout << "Test subcase: 1.3" << std::endl;
		SUBCASE("When the objects are equal")
		{
			std::cout << "Test subcase: 1.3.1" << std::endl;
			std::cout << "Testing if two objects are equal: \n";
			Dinosaur d1("Gosho", Sex::Male, Era::Jurassic, "Brontosaur", Category::Herbivores);
			CHECK(d == d1);
		}
		SUBCASE("When the objects are different")
		{
			std::cout << "Test subcase: 1.3.2" << std::endl;
			std::cout << "Testing if two objects are NOT equal: \n";
			Dinosaur d1("Maria", Sex::Female, Era::Jurassic, "Brontosaur", Category::Herbivores);
			CHECK_FALSE(d1 == d);
		}
	}
	SUBCASE("Testing the GetName() function")
	{
		std::cout << "Test subcase: 1.4" << std::endl;
		SUBCASE("If the object's name is the same as what's supposed to be returned by GetName()")
		{
			std::cout << "Test subcase: 1.4.1" << std::endl;
			std::cout << "Testing if the name the function returns is the same as the object's name: \n";
			CHECK(!strcmp(d.GetName(), "Gosho"));
		}
		SUBCASE("If the object's name is NOT the same as what's supposed to be returned by GetName()")
		{
			std::cout << "Test subcase: 1.4.2" << std::endl;
			std::cout << "Testing if the name the function returns is NOT the same as the object's name: \n";
			CHECK_FALSE(!strcmp(d.GetName(), "dsadhsa"));
		}
	}
	SUBCASE("Testing the GetSex() function")
	{
		std::cout << "Test subcase: 1.5" << std::endl;
		SUBCASE("If the object's sex is the same as what's supposed to be returned by GetSex():")
		{
			std::cout << "Test subcase: 1.5.1" << std::endl;
			std::cout << "Testing if the sex the function returns is the same as the object's sex: \n";
			CHECK_EQ(d.GetSex(), Sex::Male);
		}
		SUBCASE("If the object's sex is NOT the same as what's supposed to be returned by GetSex()")
		{
			std::cout << "Test subcase: 1.5.2" << std::endl;
			std::cout << "Testing if the sex the function returns is NOT the same as the object's sex: \n";
			CHECK_NE(d.GetSex(), Sex::Female);
		}
	}
	SUBCASE("Testing the GetEra() function")
	{
		std::cout << "Test subcase: 1.6" << std::endl;
		SUBCASE("If the object's era is the same as what's supposed to be returned by GetEra()")
		{
			std::cout << "Test subcase: 1.6.1" << std::endl;
			std::cout << "Testing if the era the function returns is the same as the object's era: \n";
			CHECK_EQ(d.GetEra(), Era::Jurassic);
		}
		SUBCASE("If the object's era is NOT the same as what's supposed to be returned by GetEra()")
		{
			std::cout << "Test subcase: 1.6.2" << std::endl;
			std::cout << "Testing if the era the function returns is NOT the same as the object's era: \n";
			CHECK_NE(d.GetEra(), Era::Cretaceous);
		}
	}
	SUBCASE("Testing the GetSpecies() function")	
	{
		std::cout << "Test subcase: 1.7" << std::endl;
		SUBCASE("If the object's species is the same as what's supposed to be returned by GetSpecies()")
		{
			std::cout << "Test subcase: 1.7.1" << std::endl;
			std::cout << "Testing if the species the function returns is the same as the object's species: \n";
			CHECK(!strcmp(d.GetSpecies(), "Brontosaur"));
		}
		SUBCASE("If the object's species is NOT the same as what's supposed to be returned by GetSpecies()")
		{
			std::cout << "Test subcase: 1.7.2" << std::endl;
			std::cout << "Testing if the species the function returns is NOT the same as the object's species: \n";
			CHECK_FALSE(!strcmp(d.GetSpecies(), "fdsbafds"));
		}
	}
	SUBCASE("Testing the GetCategory() function")
	{
		std::cout << "Test subcase: 1.8" << std::endl;
		SUBCASE("If the object's category is the same as what's supposed to be returned by GetCategory()")
		{
			std::cout << "Test subcase: 1.8.1" << std::endl;
			std::cout << "Testing if the category the function returns is the same as the object's category: \n";
			CHECK_EQ(d.GetCategory(), Category::Herbivores);
		}
		SUBCASE("If the object's era is NOT the same as what's supposed to be returned by GetCategory()")
		{
			std::cout << "Test subcase: 1.8.2" << std::endl;
			std::cout << "Testing if the category the function returns is NOT the same as the object's category: \n";
			CHECK_NE(d.GetCategory(), Category::Aquatic);
		}
	}
	SUBCASE("Testing the GetFood() function")
	{
		std::cout << "Test subcase: 1.9" << std::endl;
		SUBCASE("If the object's food is the same as what's supposed to be returned by GetFood()")
		{
			std::cout << "Test subcase: 1.9.1" << std::endl;
			std::cout << "Testing if the food the function returns is the same as the object's food: \n";
			CHECK_EQ(d.GetFood(), Food::Grass);
		}
		SUBCASE("If the object's era is NOT the same as what's supposed to be returned by GetFood()")
		{
			std::cout << "Test subcase: 1.9.2" << std::endl;
			std::cout << "Testing if the food the function returns is NOT the same as the object's food: \n";
			CHECK_NE(d.GetFood(), Food::Meat);
		}
	}
	std::cout << std::endl;
}

TEST_CASE("Testing Cage class")
{
	std::cout << "Test 2 - Cage class\n";
	Cage c(Size::Medium, Climate::Terrestrial);
	SUBCASE("Testing Copyconstructor:")
	{
		std::cout << "Test subcase: 2.1" << std::endl;
		std::cout << "Test subcase: " << std::endl;
		std::cout << "Testing if two objects are equal if one is created from the other using the copyconstructor:\n";
		Cage c1(Size::Medium, Climate::Terrestrial);
		Cage c2 = c1;
		CHECK_EQ(c1.GetSize(), c2.GetSize());
		CHECK_EQ(c1.GetCapacity(), c2.GetCapacity());
		CHECK_EQ(c1.GetClimate(), c2.GetClimate());
		CHECK_EQ(c1.GetEraOfDinosaurs(), c2.GetEraOfDinosaurs());
		CHECK_EQ(c1.GetNumberOfDinosaurs(), c2.GetNumberOfDinosaurs());
	}
	SUBCASE("Testing operator=")
	{
		std::cout << "Test subcase: 2.2" << std::endl;
		std::cout << "Test subcase: " << std::endl;
		std::cout << "Assigning one object to another and checking if they are equal after that: \n";
		Cage c1(Size::Medium, Climate::Terrestrial);
		Cage c2 = c1;
		c2 = c1;
		CHECK_EQ(c1.GetSize(), c2.GetSize());
		CHECK_EQ(c1.GetCapacity(), c2.GetCapacity());
		CHECK_EQ(c1.GetClimate(), c2.GetClimate());
		CHECK_EQ(c1.GetEraOfDinosaurs(), c2.GetEraOfDinosaurs());
		CHECK_EQ(c1.GetNumberOfDinosaurs(), c2.GetNumberOfDinosaurs());
	}
	SUBCASE("Testing the GetSize() function")
	{
		std::cout << "Test subcase: 2.3" << std::endl;
		SUBCASE("If the object's size is the same as what's supposed to be returned by GetSize()")
		{
			std::cout << "Test subcase: 2.3.1" << std::endl;
			std::cout << "Testing if the size the function returns is the same as the object's size: \n";
			CHECK_EQ(c.GetSize(), Size::Medium);
		}
		SUBCASE("If the object's size is NOT the same as what's supposed to be returned by GetSize()")
		{
			std::cout << "Test subcase: 2.3.2" << std::endl;
			std::cout << "Testing if the size the function returns is NOT the same as the object's size: \n";
			CHECK_NE(c.GetSize(), Size::Large);
		}
	}
	SUBCASE("Testing the GetClimate() function")
	{
		std::cout << "Test subcase: 2.4" << std::endl;
		SUBCASE("If the object's climate is the same as what's supposed to be returned by GetClimate()")
		{
			std::cout << "Test subcase: 2.4.1" << std::endl;
			std::cout << "Testing if the climate the function returns is the same as the object's climate: \n";
			CHECK_EQ(c.GetClimate(), Climate::Terrestrial);
		}
		SUBCASE("If the object's sex is NOT the same as what's supposed to be returned by GetSex():")
		{
			std::cout << "Test subcase: 2.4.2" << std::endl;
			std::cout << "Testing if the climate the function returns is NOT the same as the object's climate: \n";
			CHECK_NE(c.GetClimate(), Climate::Aerial);
		}
	}
	SUBCASE("Testing the GetEraOfDinosaurs() function")
	{
		std::cout << "Test subcase: 2.5" << std::endl;
		SUBCASE("If the object's era is the same as what's supposed to be returned by GetEraOfDinosaurs()")
		{
			std::cout << "Test subcase: 2.5.1" << std::endl;
			std::cout << "Testing if the era the function returns is the same as the object's era: \n";
			CHECK_EQ(c.GetEraOfDinosaurs(), Era::InvalidEra);
		}
		SUBCASE("If the object's era is NOT the same as what's supposed to be returned by GetEraOfDinosaurs()")
		{
			std::cout << "Test subcase: 2.5.2" << std::endl;
			std::cout << "Testing if the era the function returns is NOT the same as the object's era: \n";
			CHECK_NE(c.GetEraOfDinosaurs(), Era::Cretaceous);
		}
	}
	SUBCASE("Testing the GetCapacity() function")
	{
		std::cout << "Test subcase: 2.6" << std::endl;
		SUBCASE("If the object's capacity is the same as what's supposed to be returned by GetCapacity()")
		{
			std::cout << "Test subcase: 2.6.1" << std::endl;
			std::cout << "Testing if the capacity the function returns is the same as the object's capacity: \n";
			CHECK_EQ(c.GetCapacity(), 3);
		}
		SUBCASE("If the object's capacity is NOT the same as what's supposed to be returned by GetCapacity()")
		{
			std::cout << "Test subcase: 2.6.2" << std::endl;
			std::cout << "Testing if the capacity the function returns is NOT the same as the object's capacity: \n";
			CHECK_NE(c.GetCapacity(), 1);
		}	
	}
	SUBCASE("Testing the GetNumberOfDinosaurs() function")
	{
		std::cout << "Test subcase: 2.7" << std::endl;
		SUBCASE("If the object's number of dinosaurs is the same as what's supposed to be returned by GetNumberOfDinosaurs()")
		{
			std::cout << "Test subcase: 2.7.1" << std::endl;
			std::cout << "Testing if the number of dinosaurs the function returns is the same as the object's number of dinosaurs: \n";
			CHECK_EQ(c.GetNumberOfDinosaurs(), 0);
		}
		SUBCASE("If the object's number of dinosaurs is NOT the same as what's supposed to be returned by GetNumberOfDinosaurs()")
		{
			std::cout << "Test subcase: 2.7.2" << std::endl;
			std::cout << "Testing if the number of dinosaurs the function returns is the same as the object's number of dinosaurs: \n";
			CHECK_NE(c.GetNumberOfDinosaurs(), 1);
		}
	}
	SUBCASE("Testing the IsEmpty() function")
	{
		std::cout << "Test subcase: 2.8" << std::endl;
		SUBCASE("When the cage is empty")
		{
			std::cout << "Test subcase: 2.8.1" << std::endl;
			std::cout << "Testing if the cage is empty: \n";
			CHECK(c.IsEmpty());
			CHECK_EQ(c.GetNumberOfDinosaurs(), 0);
		}
		SUBCASE("When the cage is NOT empty")
		{
			std::cout << "Test subcase: 2.8.2" << std::endl;
			std::cout << "Testing if the cage is NOT empty: \n";
			c.AddDinosaur("name", Sex::Female, Era::Cretaceous, "species", Category::Carnivorous);
			CHECK_FALSE(c.IsEmpty());
			CHECK_EQ(c.GetNumberOfDinosaurs(), 1);
		}
	}
	SUBCASE("Testing the IsFull() function: ")
	{
		std::cout << "Test subcase: 2.9" << std::endl;
		SUBCASE("When the cage is full")
		{
			std::cout << "Test subcase: 2.9.1" << std::endl;
			std::cout << "Testing if the cage is full: \n";
			c.AddDinosaur("fds", Sex::Female, Era::Jurassic, "somespecies", Category::Herbivores);
			c.AddDinosaur("daio", Sex::Female, Era::Jurassic, "somespecies", Category::Herbivores);
			c.AddDinosaur("delhf", Sex::Female, Era::Jurassic, "somespecies", Category::Herbivores);
			CHECK(c.IsFull());
			CHECK_EQ(c.GetNumberOfDinosaurs(), c.GetCapacity());
		}
		SUBCASE("When the cage is NOT full")
		{
			std::cout << "Test subcase: 2.9.2" << std::endl;
			std::cout << "Testing if the cage is NOT full: \n";
			c.AddDinosaur("name", Sex::Female, Era::Cretaceous, "species", Category::Carnivorous);
			CHECK_FALSE(c.IsFull());
			CHECK_EQ(c.GetNumberOfDinosaurs(), 1);
			CHECK_NE(c.GetNumberOfDinosaurs(), c.GetCapacity());
		}
	}
	SUBCASE("Testing the AddDinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category) function")
	{
		std::cout << "Test subcase: 2.10" << std::endl;
		SUBCASE("If there are no dinosaurs in the cage /cage is empty/")
		{
			std::cout << "Test subcase: 2.10.1" << std::endl;
			std::cout << "Adding the first dinosaur in the cage:\n";
			int result = c.AddDinosaur("name", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK_EQ(c.GetNumberOfDinosaurs(), 1);
			CHECK_FALSE(c.IsEmpty());
			CHECK_EQ(result, 1);
		}
		SUBCASE("If there are some dinosaurs in the cage /cage is not empty/")
		{
			std::cout << "Test subcase: 2.10.2" << std::endl;
			std::cout << "Adding two dinosaurs in the cage:\n";
			int result1 = c.AddDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK_EQ(result1, 1);
			int result2 = c.AddDinosaur("second", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK_EQ(result2, 1);
			CHECK_FALSE(c.IsEmpty());
			CHECK_FALSE(c.IsFull());
			CHECK_EQ(c.GetNumberOfDinosaurs(), 2);
		}
		SUBCASE("When the cage is full")
		{
			std::cout << "Test subcase: 2.10.3" << std::endl;
			std::cout << "Adding capacity dinosaurs in the cage:\n";
			c.AddDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			c.AddDinosaur("second", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			c.AddDinosaur("third", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK(c.IsFull());
			std::cout << "Adding the capacity + 1 dinosaur in the cage:\n";
			int result = c.AddDinosaur("fourth", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK_EQ(result, 0);
		}
		SUBCASE("when the dinosaur is not eligible for the cage")
		{
			std::cout << "Test subcase: 2.10.4" << std::endl;
			std::cout << "Adding not eligible dinosaur in the cage:\n";
			int result = c.AddDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Flying);
			CHECK_EQ(result, 0);
		}
		SUBCASE("When the dinosaur is already in the cage")
		{
			std::cout << "Test subcase: 2.10.5" << std::endl; 
			std::cout << "Adding one dinosaur:\n";
			int result1 = c.AddDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK_EQ(result1, 1);
			std::cout << "Adding dinosaur which is already in the cage:\n";
			int result2 = c.AddDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK_EQ(result2, -1);
		}
	}
	SUBCASE("Testing the AddDinosaur(const Dinosaur& dinosaur) function")
	{
		SUBCASE("If there are no dinosaurs in the cage /cage is empty/")
		{
			Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			std::cout << "Test subcase: 2.11.1" << std::endl;
			std::cout << "Adding the first dinosaur in the cage:\n";
			int result = c.AddDinosaur(first);
			CHECK_EQ(c.GetNumberOfDinosaurs(), 1);
			CHECK_FALSE(c.IsEmpty());
			CHECK_EQ(result, 1);
		}
		SUBCASE("If there are some dinosaurs in the cage /cage is not empty/")
		{
			std::cout << "Test subcase: 2.11.2" << std::endl;
			std::cout << "Adding two dinosaurs in the cage:\n";
			Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			Dinosaur second("second", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			int result1 = c.AddDinosaur(first);
			CHECK_EQ(result1, 1);
			int result2 = c.AddDinosaur(second);
			CHECK_FALSE(c.IsEmpty());
			CHECK_FALSE(c.IsFull());
			CHECK_EQ(c.GetNumberOfDinosaurs(), 2);
			CHECK_EQ(result2, 1);
		}
		SUBCASE("When the cage is full")
		{
			Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			Dinosaur second("second", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			Dinosaur third("third", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			std::cout << "Test subcase: 2.11.3" << std::endl;
			std::cout << "Adding capacity dinosaurs in the cage:\n";
			c.AddDinosaur(first);
			c.AddDinosaur(second);
			c.AddDinosaur(third);
			CHECK(c.IsFull());
			std::cout << "Adding the capacity + 1 dinosaur in the cage:\n";
			Dinosaur fourth("fourth", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			int result = c.AddDinosaur(fourth);
			CHECK_EQ(result, 0);
		}
		SUBCASE("when the dinosaur is not eligible for the cage")
		{
			Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Flying);
			std::cout << "Test subcase: 2.11.4" << std::endl;
			std::cout << "Adding not eligible dinosaur in the cage:\n";
			int result = c.AddDinosaur(first);
			CHECK_EQ(result, 0);
		}
		SUBCASE("When the dinosaur is already in the cage")
		{
			std::cout << "Test subcase: 2.11.5" << std::endl;
			Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			Dinosaur second("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			std::cout << "Adding one dinosaur:\n";
			int result1 = c.AddDinosaur(first);
			CHECK_EQ(result1, 1);
			std::cout << "Adding dinosaur which is already in the cage:\n";
			int result2 = c.AddDinosaur(second);
			CHECK_EQ(result2, -1);
		}
	}
	SUBCASE("Testing RemoveDinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category) function")
	{
		SUBCASE("If the cage is empty")
		{
			std::cout << "Test subcase: 2.12.1" << std::endl;
			std::cout << "Removing one dinosaurs in the cage:\n";
			bool result = c.RemoveDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK_FALSE(result);
		}
		SUBCASE("When the dinosaur is in the cage")
		{
			std::cout << "Test subcase: 2.12.2" << std::endl;
			std::cout << "Adding one dinosaurs in the cage:\n";
			c.AddDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			std::cout << "Removing the dinosaurs in the cage:\n";
			bool result = c.RemoveDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK(result);
		}
		SUBCASE("When dinosaur is not in the cage")
		{
			std::cout << "Test subcase: 2.12.3" << std::endl;
			std::cout << "Adding one dinosaurs in the cage:\n";
			c.AddDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			std::cout << "Removing the dinosaurs in the cage:\n";
			bool result = c.RemoveDinosaur("sdadbasj", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK_FALSE(result);
			CHECK_EQ(c.GetNumberOfDinosaurs(), 1);
		}
	}
	SUBCASE("Testing RemoveDinosaur() function")
	{
		SUBCASE("If the cage is empty")
		{
			std::cout << "Test subcase: 2.13.1" << std::endl;
			std::cout << "Removing one dinosaurs in the cage:\n";
			Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			bool result = c.RemoveDinosaur(first);
			CHECK_FALSE(result);
		}
		SUBCASE("When the dinosaur is in the cage")
		{
			std::cout << "Test subcase: 2.13.2" << std::endl;
			std::cout << "Adding one dinosaurs in the cage:\n";
			Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			c.AddDinosaur(first);
			std::cout << "Removing the dinosaurs in the cage:\n";
			bool result = c.RemoveDinosaur(first);
			CHECK(result);
		}
		SUBCASE("When dinosaur is not in the cage")
		{
			std::cout << "Test subcase: 2.13.3" << std::endl;
			std::cout << "Adding one dinosaurs in the cage:\n";
			Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			c.AddDinosaur(first);
			Dinosaur sdadbasj("sdadbasj", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			std::cout << "Removing the dinosaurs in the cage:\n";
			bool result = c.RemoveDinosaur(sdadbasj);
			CHECK_FALSE(result);
			CHECK_EQ(c.GetNumberOfDinosaurs(), 1);
		}
	}
	std::cout << std::endl;
}

TEST_CASE("Tesing FoodStorage struct")
{
	std::cout << "Test 3 - DinosaurPark class\n";
	SUBCASE("Testing operator-=")
	{
		std::cout << "Test subcase: 3.1" << std::endl;
		FoodStorage f1(10, 10, 10);
		FoodStorage f2(3, 3, 3);
		FoodStorage f3(f1);
		f1 -= f2;
		CHECK_EQ(f1.fish, f3.fish - f2.fish);
		CHECK_EQ(f1.meat, f3.meat - f2.meat);
		CHECK_EQ(f1.grass, f3.grass - f2.grass);
	}
	SUBCASE("Testing operator-")
	{
		std::cout << "Test subcase: 3.2" << std::endl;
		FoodStorage f1(10, 10, 10);
		FoodStorage f2(3, 3, 3);
		FoodStorage f3;
		f3 = f1 - f2;
		CHECK_EQ(f3.fish, f1.fish - f2.fish);
		CHECK_EQ(f3.meat, f1.meat - f2.meat);
		CHECK_EQ(f3.grass, f1.grass - f2.grass);
	}
	SUBCASE("Testing operator<")
	{
		std::cout << "Test subcase: 3.3" << std::endl;
		FoodStorage f1(10, 10, 10);
		FoodStorage f2(3, 3, 3);
		CHECK(f2 < f1);
	}
	std::cout << std::endl;
}

TEST_CASE("Testing DinosaurPark class")
{
	std::cout << "Test 4 - DinosaurPark class\n";
	DinosaurPark p;
	SUBCASE("Testing the GetNumberOfCages() function")
	{
		std::cout << "Test subcase: 4.1" << std::endl;
		SUBCASE("If the object's number of cages is the same as what's supposed to be returned by GetNumberOfCages()")
		{
			std::cout << "Test subcase: 4.1.1" << std::endl;
			std::cout << "Testing if the number of cages the function returns is the same as the object's number of cages: \n";
			CHECK_EQ(p.GetNumberOfCages(), 3);
		}
		SUBCASE("If the object's number of cages is NOT the same as what's supposed to be returned by GetNumberOfCages()")
		{
			std::cout << "Test subcase: 4.1.2" << std::endl;
			std::cout << "Testing if the number of cages the function returns is NOT the same as the object's number of cages: \n";
			CHECK_NE(p.GetNumberOfCages(), 2);
		}
	}
	SUBCASE("Testing the GetMaxNumberOfCages() function")
	{
		std::cout << "Test subcase: 4.2" << std::endl;
		SUBCASE("If the object's number of cages is the same as what's supposed to be returned by GetMaxNumberOfCages()")
		{
			std::cout << "Test subcase: 4.2.1" << std::endl;
			std::cout << "Testing if the max number of cages the function returns is the same as the object's max number of cages: \n";
			CHECK_EQ(p.GetMaxNumberOfCages(), 4);
		}
		SUBCASE("If the object's number of cages is NOT the same as what's supposed to be returned by GetMaxNumberOfCages()")
		{
			std::cout << "Test subcase: 4.2.2" << std::endl;
			std::cout << "Testing if the max number of cages the function returns is NOT the same as the object's max number of cages: \n";
			CHECK_NE(p.GetMaxNumberOfCages(), 1);
		}
	}
	SUBCASE("Testing the GetCages() function")
	{
		std::cout << "Test subcase: 4.3" << std::endl;
		SUBCASE("If the object's number of cages is the same as what's supposed to be returned by GetMaxNumberOfCages()")
		{
			std::cout << "Test subcase: 4.3.1" << std::endl;
			std::cout << "Testing if the staff count the function returns is the same as the object's staff count: \n";
			CHECK_EQ(p.GetStaffCount(), 3);
		}
		SUBCASE("If the object's number of cages is NOT the same as what's supposed to be returned by GetMaxNumberOfCages()")
		{
			std::cout << "Test subcase: 4.3.2" << std::endl;
			std::cout << "Testing if the staff count the function returns is NOT the same as the object's staff count: \n";
			CHECK_NE(p.GetStaffCount(), 1);
		}
	}	
	SUBCASE("Testing the GetFoodRequired() function")
	{
		FoodStorage f1(0, 0, 0);
		FoodStorage f2(1, 2, 3);
		std::cout << "Test subcase: 4.4" << std::endl;
		SUBCASE("If the object's foodRequred is the same as what's supposed to be returned by GetFoodRequred()")
		{
			std::cout << "Test subcase: 4.4.1" << std::endl;
			std::cout << "Testing if the food requred the function returns is the same as the object's food required: \n";
			CHECK_EQ(p.GetFoodRequired().fish, f1.fish);
			CHECK_EQ(p.GetFoodRequired().meat, f1.meat);
			CHECK_EQ(p.GetFoodRequired().grass, f1.grass);
		}
		SUBCASE("If the object's foodRequred is NOT the same as what's supposed to be returned by GetFoodRequred()")
		{
			std::cout << "Test subcase: 4.4.2" << std::endl;
			std::cout << "Testing if the food requred the function returns is NOT the same as the object's food requred: \n";
			CHECK_NE(p.GetFoodRequired().fish, f2.fish);
			CHECK_NE(p.GetFoodRequired().meat, f2.meat);
			CHECK_NE(p.GetFoodRequired().grass, f2.grass);
		}
	}
	SUBCASE("Testing the GetFoodAvailable() function")
	{
		FoodStorage f1(10, 10, 10);
		FoodStorage f2(1, 2, 3);
		std::cout << "Test subcase: 4.5" << std::endl;
		SUBCASE("If the object's foodAvailable is the same as what's supposed to be returned by GetFoodAvailable()")
		{
			std::cout << "Test subcase: 4.5.1" << std::endl;
			std::cout << "Testing if the food available the function returns is the same as the object's food available: \n";
			CHECK_EQ(p.GetFoodAvailable().fish, f1.fish);
			CHECK_EQ(p.GetFoodAvailable().meat, f1.meat);
			CHECK_EQ(p.GetFoodAvailable().grass, f1.grass);
		}
		SUBCASE("If the object's foodAvailable is NOT the same as what's supposed to be returned by GetFoodAvailable()")
		{
			std::cout << "Test subcase: 4.5.2" << std::endl;
			std::cout << "Testing if the food available the function returns is NOT the same as the object's food available: \n";
			CHECK_NE(p.GetFoodAvailable().fish, f2.fish);
			CHECK_NE(p.GetFoodAvailable().meat, f2.meat);
			CHECK_NE(p.GetFoodAvailable().grass, f2.grass);
		}
	}
	SUBCASE("Testing copyconstructor:")
	{
		std::cout << "Test subcase: 4.6" << std::endl;
		std::cout << "Testing if two objects are equal if one is created from the other using the copyconstructor:\n";
		p.AddDinosaur("name", Sex::Female, Era::Cretaceous, "species", Category::Aquatic);
		DinosaurPark p1 = p;
		CHECK_EQ(p.GetStaffCount(), p1.GetStaffCount());
		CHECK_EQ(p.GetNumberOfCages(), p1.GetNumberOfCages());
		CHECK_EQ(p.GetMaxNumberOfCages(), p1.GetMaxNumberOfCages());
		CHECK_EQ(p.GetFoodAvailable().fish, p1.GetFoodAvailable().fish);
		CHECK_EQ(p.GetFoodAvailable().meat, p1.GetFoodAvailable().meat);
		CHECK_EQ(p.GetFoodAvailable().grass, p1.GetFoodAvailable().grass);
		CHECK_EQ(p.GetFoodRequired().fish, p1.GetFoodRequired().fish);
		CHECK_EQ(p.GetFoodRequired().meat, p1.GetFoodRequired().meat);
		CHECK_EQ(p.GetFoodRequired().grass, p1.GetFoodRequired().grass);
	}
	SUBCASE("Testing operator=")
	{
		std::cout << "Test subcase: 4.7" << std::endl;
		std::cout << "Adding one dinosaur and assigning one object to another and checking if they are equal after that: \n";
		DinosaurPark p1;
		p.AddDinosaur("name", Sex::Female, Era::Cretaceous, "species", Category::Aquatic);
		p1 = p;
		CHECK_EQ(p.GetStaffCount(), p1.GetStaffCount());
		CHECK_EQ(p.GetNumberOfCages(), p1.GetNumberOfCages());
		CHECK_EQ(p.GetMaxNumberOfCages(), p1.GetMaxNumberOfCages());
		CHECK_EQ(p.GetFoodAvailable().fish, p1.GetFoodAvailable().fish);
		CHECK_EQ(p.GetFoodAvailable().meat, p1.GetFoodAvailable().meat);
		CHECK_EQ(p.GetFoodAvailable().grass, p1.GetFoodAvailable().grass);
		CHECK_EQ(p.GetFoodRequired().fish, p1.GetFoodRequired().fish);
		CHECK_EQ(p.GetFoodRequired().meat, p1.GetFoodRequired().meat);
		CHECK_EQ(p.GetFoodRequired().grass, p1.GetFoodRequired().grass);
	}
	SUBCASE("Testing CreateCage(const Size size, const Climate climate) function")
	{
		std::cout << "Test subcase: 4.8" << std::endl;
		SUBCASE("When there are just the three cages generated by the constructor")
		{
			std::cout << "Test subcase: 4.8.1" << std::endl;
			std::cout << "Creating one cage:\n";
			p.CreateCage(Size::Medium, Climate::Terrestrial);
			CHECK_EQ(p.GetNumberOfCages(), 4);
			CHECK_EQ(p.GetMaxNumberOfCages(), p.GetNumberOfCages());
		}
		SUBCASE("Whene numberOfCages is equal to maxNumberOfCages and the container have to be resized")
		{
			std::cout << "Test subcase: 4.8.2" << std::endl;
			std::cout << "Creating one cage:\n";
			p.CreateCage(Size::Small, Climate::Aerial);
			std::cout << "Creating one more cage which would call the Resize() function and double the amount of cages that can be stored\n";
			p.CreateCage(Size::Medium, Climate::Aqueous);
			CHECK_EQ(p.GetNumberOfCages(), 5);
			CHECK_EQ(p.GetMaxNumberOfCages(), 8);
		}
	}
	SUBCASE("Testing CreateCage(const Cage& cage)")
	{
		std::cout << "Test subcase: 4.9" << std::endl;
		SUBCASE("When there are just the three cages generated by the constructor")
		{
			std::cout << "Test subcase: 4.10.1" << std::endl;
			std::cout << "Creating one cage:\n";
			Cage first(Size::Small, Climate::Aerial);
			p.CreateCage(first);
			CHECK_EQ(p.GetNumberOfCages(), 4);
			CHECK_EQ(p.GetMaxNumberOfCages(), p.GetNumberOfCages());
		}
		SUBCASE("Whene numberOfCages is equal to maxNumberOfCages and the container have to be resized")
		{
			std::cout << "Test subcase: 4.9.2" << std::endl;
			std::cout << "Creating one cage:\n";
			Cage first(Size::Small, Climate::Aerial);
			p.CreateCage(first);
			std::cout << "Creating one more cage which would call the Resize() function and double the amount of cages that can be stored\n";
			Cage second(Size::Medium, Climate::Aqueous);
			p.CreateCage(second);
			CHECK_EQ(p.GetNumberOfCages(), 5);
			CHECK_EQ(p.GetMaxNumberOfCages(), 8);
		}
	}
	SUBCASE("Testing the AddDinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category) function")
	{
		std::cout << "Test subcase: 4.10" << std::endl;
		SUBCASE("If there are no dinosaurs in the cage /cage is empty/")
		{
			std::cout << "Test subcase: 4.10.1" << std::endl;
			std::cout << "Adding the first dinosaur in the cage:\n";
			int result = p.AddDinosaur("name", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			bool isInSomeCage = false;
			for (int i = 0; i < p.GetNumberOfCages(); i++)
			{
				for (int j = 0; j < p.GetCages()[i].GetNumberOfDinosaurs(); j++)
				{
					if (p.GetCages()[i].GetDinosaurs()[j] == Dinosaur("name", Sex::Male, Era::Triassic, "species", Category::Carnivorous))
					{
						isInSomeCage = true;
						break;
					}
				}
			}
			CHECK(isInSomeCage);
			CHECK_EQ(result, 1);
		}
		SUBCASE("If there are some dinosaurs in the cage /cage is not empty/")
		{
			std::cout << "Test subcase: 4.10.2" << std::endl;
			std::cout << "Adding two dinosaurs in the cage:\n";
			int result1 = p.AddDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK_EQ(result1, 1);
			bool isInSomeCage = false;
			int result2 = p.AddDinosaur("second", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			int i = 0;
			while (i < p.GetNumberOfCages())
			{
				for (int j = 0; j < p.GetCages()[i].GetNumberOfDinosaurs(); j++)
				{
					if (p.GetCages()[i].GetDinosaurs()[j] == Dinosaur("second", Sex::Male, Era::Triassic, "species", Category::Carnivorous))
					{
						isInSomeCage = true;
						break;
					}
				}
				if (isInSomeCage)
				{
					break;
				}
				i++;
			}
			CHECK(isInSomeCage);
			CHECK_EQ(result2, 1);
			CHECK_FALSE(p.GetCages()[i].IsEmpty());
			CHECK_FALSE(p.GetCages()[i].IsFull());
			CHECK_EQ(p.GetCages()[i].GetNumberOfDinosaurs(), 2);
		}
		SUBCASE("When the cage is full")
		{
			std::cout << "Test subcase: 4.10.3" << std::endl;
			std::cout << "Adding capacity dinosaurs in the cage:\n";
			p.AddDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Flying);
			p.AddDinosaur("second", Sex::Male, Era::Triassic, "species", Category::Flying);
			p.AddDinosaur("third", Sex::Male, Era::Triassic, "species", Category::Flying);
			CHECK(p.GetCages()[0].IsFull());
			std::cout << "Adding the capacity + 1 dinosaur in the cage:\n";
			int result = p.AddDinosaur("fourth", Sex::Male, Era::Triassic, "species", Category::Flying);
			CHECK_EQ(result, 0);
		}
		SUBCASE("When the dinosaur is not eligible for any the cage")
		{
			std::cout << "Test subcase: 4.10.4" << std::endl;
			std::cout << "Adding one dinosaur in a cage:\n";
			int result = p.AddDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Flying);
			CHECK_EQ(result, 1);
			std::cout << "Adding not eligible dinosaur in a cage:\n";
			result = p.AddDinosaur("first", Sex::Male, Era::Cretaceous, "species", Category::Flying);
			CHECK_EQ(result, 0);
		}
		SUBCASE("When the dinosaur is already in the cage")
		{
			std::cout << "Test subcase: 4.10.5" << std::endl; 
			std::cout << "Adding one dinosaur:\n";
			int result1 = p.AddDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK_EQ(result1, 1);
			std::cout << "Adding dinosaur which is already in some cage:\n";
			int result2 = p.AddDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK_EQ(result2, -1);
		}
	}
	SUBCASE("Testing the AddDinosaur(const Dinosaur& dinosaur) function")
	{
		std::cout << "Test subcase: 4.11" << std::endl;
		SUBCASE("If there are no dinosaurs in the cage /cage is empty/")
		{
			std::cout << "Test subcase: 4.11.1" << std::endl;
			std::cout << "Adding the first dinosaur in the cage:\n";
			Dinosaur first("name", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			int result = p.AddDinosaur(first);
			bool isInSomeCage = false;
			for (int i = 0; i < p.GetNumberOfCages(); i++)
			{
				for (int j = 0; j < p.GetCages()[i].GetNumberOfDinosaurs(); j++)
				{
					if (p.GetCages()[i].GetDinosaurs()[j] == Dinosaur("name", Sex::Male, Era::Triassic, "species", Category::Carnivorous))
					{
						isInSomeCage = true;
						break;
					}
				}
			}
			CHECK(isInSomeCage);
			CHECK_EQ(result, 1);
		}
		SUBCASE("If there are some dinosaurs in the cage /cage is not empty/")
		{
			std::cout << "Test subcase: 4.11.2" << std::endl;
			std::cout << "Adding two dinosaurs in the cage:\n";
			Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			int result1 = p.AddDinosaur(first);
			CHECK_EQ(result1, 1);
			bool isInSomeCage = false;
			Dinosaur second("second", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			int result2 = p.AddDinosaur(second);
			int i = 0;
			while (i < p.GetNumberOfCages())
			{
				for (int j = 0; j < p.GetCages()[i].GetNumberOfDinosaurs(); j++)
				{
					if (p.GetCages()[i].GetDinosaurs()[j] == Dinosaur("second", Sex::Male, Era::Triassic, "species", Category::Carnivorous))
					{
						isInSomeCage = true;
					}
				}
				if (isInSomeCage)
				{
					break;
				}
				i++;
			}
			CHECK(isInSomeCage);
			CHECK_EQ(result2, 1);
			CHECK_FALSE(p.GetCages()[i].IsEmpty());
			CHECK_FALSE(p.GetCages()[i].IsFull());
			CHECK_EQ(p.GetCages()[i].GetNumberOfDinosaurs(), 2);
		}
		SUBCASE("When the cage is full")
		{
			std::cout << "Test subcase: 4.11.3" << std::endl;
			std::cout << "Adding capacity dinosaurs in the cage:\n";
			Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Flying);
			Dinosaur second("second", Sex::Male, Era::Triassic, "species", Category::Flying);
			Dinosaur third("third", Sex::Male, Era::Triassic, "species", Category::Flying);
			p.AddDinosaur(first);
			p.AddDinosaur(second);
			p.AddDinosaur(third);
			CHECK(p.GetCages()[0].IsFull());
			std::cout << "Adding the capacity + 1 dinosaur in the cage:\n";
			Dinosaur fourth("fourth", Sex::Male, Era::Triassic, "species", Category::Flying);
			int result = p.AddDinosaur(fourth);
			CHECK_EQ(result, 0);
		}
		SUBCASE("When the dinosaur is not eligible for any the cage")
		{
			std::cout << "Test subcase: 4.11.4" << std::endl;
			std::cout << "Adding one dinosaur in a cage:\n";
			Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Flying);
			int result = p.AddDinosaur(first);
			CHECK_EQ(result, 1);
			std::cout << "Adding not eligible dinosaur in a cage:\n";
			Dinosaur second("second", Sex::Male, Era::Cretaceous, "species", Category::Flying);
			result = p.AddDinosaur(second);
			CHECK_EQ(result, 0);
		}
		SUBCASE("When the dinosaur is already in the cage")
		{
			std::cout << "Test subcase: 4.11.5" << std::endl;
			std::cout << "Adding one dinosaur:\n";
			Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			int result1 = p.AddDinosaur(first);
			CHECK_EQ(result1, 1);
			std::cout << "Adding dinosaur which is already in some cage:\n";
			int result2 = p.AddDinosaur(first);
			CHECK_EQ(result2, -1);
		}
	}
	SUBCASE("Testing RemoveDinosaur(const char* name, const Sex sex, const Era era, const char* species, const Category category) function")
	{
		std::cout << "Test subcase: 4.12" << std::endl;
		SUBCASE("If the cage is empty")
		{
			std::cout << "Test subcase: 4.12.1" << std::endl;
			std::cout << "Removing one dinosaurs in the cage:\n";
			bool result = p.RemoveDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK_FALSE(result);
		}
		SUBCASE("When the dinosaur is in the cage")
		{
			std::cout << "Test subcase: 4.12.2" << std::endl;
			std::cout << "Adding one dinosaurs in the cage:\n";
			p.AddDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			std::cout << "Removing the dinosaurs in the cage:\n";
			bool result = p.RemoveDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK(result);
		}
		SUBCASE("When dinosaur is not in the cage")
		{
			std::cout << "Test subcase: 4.12.3" << std::endl;
			std::cout << "Adding one dinosaurs in the cage:\n";
			p.AddDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			std::cout << "Removing the dinosaurs in the cage:\n";
			bool result = p.RemoveDinosaur("sdadbasj", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			CHECK_FALSE(result);
			CHECK_EQ(p.GetCages()[2].GetNumberOfDinosaurs(), 1);
		}
	}
	SUBCASE("Testing RemoveDinosaur() function")
	{
		std::cout << "Test subcase: 4.13" << std::endl;
		SUBCASE("When every cage is empty")
		{
			std::cout << "Test subcase: 4.13.1" << std::endl;
			std::cout << "Removing one dinosaurs in the cage:\n";
			Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			bool result = p.RemoveDinosaur(first);
			CHECK_FALSE(result);
		}
		SUBCASE("When the dinosaur is in a the cage")
		{
			std::cout << "Test subcase: 4.13.2" << std::endl;
			std::cout << "Adding one dinosaurs in the cage:\n";
			Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			p.AddDinosaur(first);
			std::cout << "Removing the dinosaurs in the cage:\n";
			bool result = p.RemoveDinosaur(first);
			CHECK(result);
		}
		SUBCASE("When dinosaur is NOT in any cage")
		{
			std::cout << "Test subcase: 4.13.3" << std::endl;
			std::cout << "Adding one dinosaurs in the cage:\n";
			Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			p.AddDinosaur(first);
			Dinosaur sdadbasj("sdadbasj", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
			std::cout << "Removing the dinosaurs in the cage:\n";
			bool result = p.RemoveDinosaur(sdadbasj);
			CHECK_FALSE(result);
			CHECK_EQ(p.GetCages()[2].GetNumberOfDinosaurs(), 1);
		}
	}
	SUBCASE("Testing RefillStorage() function")
	{
		std::cout << "Test subcase: 4.14" << std::endl;
		std::cout << "Adding 3 dinosaurs:\n";
		p.AddDinosaur("first", Sex::Male, Era::Triassic, "species", Category::Herbivores);
		p.AddDinosaur("second", Sex::Male, Era::Triassic, "species", Category::Aquatic);
		p.AddDinosaur("third", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
		p.RefillStorage();
		CHECK_EQ(p.GetFoodAvailable().grass, 4);
		CHECK_EQ(p.GetFoodAvailable().meat, 4);
		CHECK_EQ(p.GetFoodAvailable().fish, 4);
	}
	SUBCASE("Testing FeedTheDinosaurs() function")
	{
		std::cout << "Test subcase: 4.15" << std::endl;
		std::cout << "Adding 4 dinosaurs:\n";
		Dinosaur first("first", Sex::Male, Era::Triassic, "species", Category::Flying);
		Dinosaur second("second", Sex::Male, Era::Triassic, "species", Category::Aquatic);
		Dinosaur third("third", Sex::Male, Era::Triassic, "species", Category::Carnivorous);
		Dinosaur fourth("Fourth", Sex::Male, Era::Triassic, "species", Category::Herbivores);
		p.AddDinosaur(first);
		p.AddDinosaur(second);
		p.AddDinosaur(third);
		p.AddDinosaur(fourth);
		CHECK_EQ(p.GetFoodAvailable().grass, 10);
		CHECK_EQ(p.GetFoodAvailable().meat, 10);
		CHECK_EQ(p.GetFoodAvailable().fish, 10);
		p.FeedTheDinosaurs();
		if (first.GetFood() == Food::Meat)
		{
			CHECK_EQ(p.GetFoodAvailable().meat, 8);
			CHECK_EQ(p.GetFoodAvailable().fish, 9);
		}
		else
		{
			CHECK_EQ(p.GetFoodAvailable().meat, 9);
			CHECK_EQ(p.GetFoodAvailable().fish, 8);
		}
		CHECK_EQ(p.GetFoodAvailable().grass, 9);
	}
	std::cout << std::endl;
}