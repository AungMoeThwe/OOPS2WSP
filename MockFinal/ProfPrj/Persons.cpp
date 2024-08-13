#include <iostream>
#include "Persons.h"

Person::Person(const string& n, const string& sid, const string& accNum, double climit, double cBalance) : name(n), socialID(sid), accountNumber(accNum), creditLimit(climit), creditBalance(cBalance) {}

Person::Person(const Person& p)
{
	name = p.name;
	socialID = p.socialID;
	accountNumber = p.accountNumber;
	creditLimit = p.creditLimit;
	creditBalance = p.creditBalance;

}

Person& Person::operator = (const Person& p)
{
	if (this != &p)
	{
		name = p.name;
		socialID = p.socialID;
		accountNumber = p.accountNumber;
		creditLimit = p.creditLimit;
		creditBalance = p.creditBalance;
	}
	return *this;
}





std::string Person::getName() const {return name;}

std::string Person::getSocialID() const {return socialID;}

std::string Person::getAccountNumber() const {return accountNumber;}

double Person::getCreditLimit() const {return creditLimit;}

double Person::getCreditBalance() const {return creditBalance;}

void Person::display() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Social ID: " << socialID << std::endl;
	std::cout << "Account Number: " << accountNumber << std::endl;
	std::cout << "Credit Limit: " << creditLimit << std::endl;
	std::cout << "Credit Balance: " << creditBalance << std::endl;
}

