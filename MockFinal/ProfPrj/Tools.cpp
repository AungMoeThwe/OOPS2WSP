#include <iostream>
#include "Tools.h"


bool checkSocialID(const std::string& sid, Person* persons[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (persons[i]->getSocialID() == sid)
			return false;
	}
	return true;
}

bool checkAccountNumber(const std::string& accNum, Person* persons[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (persons[i]->getAccountNumber() == accNum)
			return false;
	}
	return true;
}



// Function to get input for persons
void getInput(Person** persons, int numPersons) {

	// Initialising Variables for temporary input storage
	std::string name, socialID, accNumber;
	double creditLimit, creditBalance;

	for (int i = 0; i < numPersons; ++i) {
		std::cout << "Enter details for person " << i + 1 << ":\n";
		std::cout << "Name: ";
		std::getline(std::cin, name);

		do {
			std::cout << "Social ID: ";
			std::getline(std::cin, socialID);
			if (!checkSocialID(socialID, persons, i)) {
				std::cout << "Social ID already exists. Please enter a unique Social ID.\n";
			}
		} while (!checkSocialID(socialID, persons, i)); //make sure that social id is unique and not repeting

		do {
			std::cout << "Account Number: ";
			std::getline(std::cin, accNumber);
			if (!checkAccountNumber(accNumber, persons, i)) {
				std::cout << "Account Number already exists. Please enter a unique Account Number.\n";
			}
		} while (!checkAccountNumber(accNumber, persons, i)); //make sure that account number is unique and not repeting

		std::cout << "Credit Limit: ";
		std::cin >> creditLimit;
		std::cin.ignore(); // Ignore remaining newline character

		std::cout << "Credit Balance: ";
		std::cin >> creditBalance;
		std::cin.ignore(); // Ignore remaining newline character

		persons[i] = new Person(name, socialID, accNumber, creditLimit, creditBalance);
	}
}

// Comparison functions
bool compareByName(Person* a, Person* b) {
	return a->getName() > b->getName();
}

bool compareBySocialID(Person* a, Person* b) {
	return a->getSocialID() > b->getSocialID();
}

bool compareByAccountNumber(Person* a, Person* b) {
	return a->getAccountNumber() > b->getAccountNumber();
}

bool compareByCreditLimit(Person* a, Person* b) {
	return a->getCreditLimit() > b->getCreditLimit();
}

bool compareByCreditBalance(Person* a, Person* b) {
	return a->getCreditBalance() > b->getCreditBalance();
}