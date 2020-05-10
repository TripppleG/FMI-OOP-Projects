#pragma once

enum class Sex 
{
    Male = 1,
    Female,
    InvalidSex = -1
};

enum class Era 
{
    Triassic = 1, 
    Cretaceous, 
    Jurassic,
    InvalidEra = -1
};
enum class Category 
{
    Aquatic = 1,
    Carnivorous,
    Flying,
    Herbivores,
    InvalidCategory = -1
};
enum class Food 
{
    Meat = 1,
    Grass,
    Fish,
    InvalidFood = -1
};

enum class Size
{
    Small = 1,
    Medium,
    Large,
    InvalidSize = -1
};

enum class Climate
{
    Terrestrial = 1,
    Aerial,
    Aqueous,
    InvalidClimate = -1
};