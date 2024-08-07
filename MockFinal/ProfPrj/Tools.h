#ifndef OOP224_TOOLS_H
#define OOP224_TOOLS_H

#include "Persons.h"

//Function to check for uique socialid
bool checkSocialID(const std::string& sid, Person* persons[], int size);

template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


template <typename T, typename Compare>
void sort(T* arr[], int size, Compare comp)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (comp(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
//Templates are in header file to not instiatiate.

//void getInput(int num, Person* persons[]);
void getInput(Person** persons, int numPersons);

//Comparison for each field 
bool compareByName(Person* a, Person* b);
bool compareBySocialID(Person* a, Person* b);
bool compareByAge(Person* a, Person* b);
bool compareByOccupation(Person* a, Person* b);
bool compareByIncome(Person* a, Person* b);

#endif // !OOP224_TOOLS_H
