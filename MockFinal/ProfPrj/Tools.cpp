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



// Function to get input for persons
void getInput(Person** persons, int numPersons) {

	// Initialising Variables for temporary input storage
	std::string name, socialID, occupation;
	int age;
	double income;

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

		std::cout << "Age: ";
		std::cin >> age;
		std::cin.ignore(); // Ignore remaining newline character

		std::cout << "Occupation: ";
		std::getline(std::cin, occupation);

		std::cout << "Income: ";
		std::cin >> income;
		std::cin.ignore(); // Ignore remaining newline character

		persons[i] = new Person(name, socialID, age, occupation, income);
	}
}

// Comparison functions
bool compareByName(Person* a, Person* b) {
	return a->getName() > b->getName();
}

bool compareBySocialID(Person* a, Person* b) {
	return a->getSocialID() > b->getSocialID();
}

bool compareByAge(Person* a, Person* b) {
	return a->getAge() > b->getAge();
}

bool compareByOccupation(Person* a, Person* b) {
	return a->getOccupation() > b->getOccupation();
}

bool compareByIncome(Person* a, Person* b) {
	return a->getIncome() > b->getIncome();
}