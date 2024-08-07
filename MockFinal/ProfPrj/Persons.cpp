#include <iostream>
#include "Persons.h"

Person::Person(const std::string& n, const std::string& sid, int a, const std::string& occ, double inc)
	: name(n), socialID(sid), age(a), occupation(occ), income(inc) {}

Person::Person(const Person& p)
{
	name = p.name;
	socialID = p.socialID;
	age = p.age;
	occupation = p.occupation;
	income = p.income;

}

Person& Person::operator = (const Person& p)
{
	if (this != &p)
	{
		name = p.name;
		socialID = p.socialID;
		age = p.age;
		occupation = p.occupation;
		income = p.income;
	}
	return *this;
}

Person::~Person()
{
}



std::string Person::getName() const {return name;}

std::string Person::getSocialID() const {return socialID;}

int Person::getAge() const {return age;}

std::string Person::getOccupation() const {return occupation;}

double Person::getIncome() const {return income;}

void Person::display() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Social ID: " << socialID << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Occupation: " << occupation << std::endl;
	std::cout << "Income: " << income << std::endl;
}

