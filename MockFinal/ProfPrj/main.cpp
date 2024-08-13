#include <iostream>
#include "Persons.h"
#include "Tools.h"

int main() {

	int numPersons;
	std::cout << "Enter the number of persons: ";
	std::cin >> numPersons;
	std::cin.ignore(); // Ignore remaining newline character

	Person** persons = new Person * [numPersons];

	// Get input for persons
	getInput(persons, numPersons);

	int choice;
	do {
		std::cout << "Sort by:\n1. Name\n2. Social ID\n3. Account Number\n4. Credit Limit\n5. Credit Balance\n0. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			sort(persons, numPersons, compareByName);
			break;
		case 2:
			sort(persons, numPersons, compareBySocialID);
			break;
		case 3:
			sort(persons, numPersons, compareByAccountNumber);
			break;
		case 4:
			sort(persons, numPersons, compareByCreditLimit);
			break;
		case 5:
			sort(persons, numPersons, compareByCreditBalance);
			break;
		case 0:
			std::cout << "Exiting the program." << std::endl;
			break;
		default:
			std::cout << "Invalid choice!" << std::endl;
			break;
		}

		if (choice != 0) {
			// Display sorted persons
			std::cout << "\nSorted persons:\n";
			for (int i = 0; i < numPersons; ++i) {
				persons[i]->display();
				std::cout << std::endl;
			}
		}

	} while (choice != 0);

	// Clean up memory
	for (int i = 0; i < numPersons; ++i) {
		delete persons[i];
	}
	delete[] persons;
	return 0;
}
