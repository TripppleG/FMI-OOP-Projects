#include "doctest.h"
#include "DinosaurPark.h"
#include <iomanip>


TEST_CASE("Testing Dinosaur class")
{
	std::cout << "Test 1 - Testing Dinosaur class";
	static int subcases = 1;
	Dinosaur defaultDinosaur;
	Dinosaur nonDefaultDinosaur("Gosho", Sex::Male, Era::Jurassic, "Brontosaur", Category::Herbivores);
	SUBCASE("Testing ")
	{
		std::cout << "Test subcase: " << subcases << std::endl;
	}
}

