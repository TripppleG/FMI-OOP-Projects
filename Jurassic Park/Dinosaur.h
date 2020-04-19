#pragma once
#include <iostream>

class Dinosaur
{
	void SetName(const char* name);
	void SetSex(const char sex);
	void SetEra(const char* era);
	void SetSpecies(const char* species);

	virtual void SetFood() = 0;
	virtual void SetCategory() = 0;

	void CopyFrom(const Dinosaur& other);
	void Free();
protected:
	char* name;
	char sex;
	char* era;
	char* category;
	char* species;
	char* food;
public:
	Dinosaur() {}
	Dinosaur(const char* name, const char sex, const char* era, const char* species);
	Dinosaur(const Dinosaur& other);
	Dinosaur& operator=(const Dinosaur& other);
	~Dinosaur();

	const char* GetName() const;
	const char GetSex() const;
	const char* GetEra() const;
	const char* GetSpecies() const;
	const char* GetCategory() const;
	const char* GetFood() const;
	virtual Dinosaur* Clone()const = 0;
};