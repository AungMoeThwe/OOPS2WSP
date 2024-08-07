#ifndef OOP224_PERSONS_H
#define OOP224_PERSONS_H

#include <iostream>
#include <string>


class Person
{
	std::string name{};
	std::string socialID{};
	int age{};
	std::string occupation{};
	double income{};

public:
	//Constructors with arguments
	Person(const std::string& n = "", const std::string& sid = "", int a = 0, const std::string& occ = "", double inc = 0.0);

	//Rule of 3
	//Copy Constructor
	Person(const Person& p);
	// Copy Assignment
	Person& operator = (const Person& p);
	//Destructor
	~Person();

	//Query functions
	std::string getName() const;
	std::string getSocialID() const;
	int getAge() const;
	std::string getOccupation() const;
	double getIncome() const;

	//Display functions
	void display() const;
};




#endif // !OOP224_PERSONS_H
