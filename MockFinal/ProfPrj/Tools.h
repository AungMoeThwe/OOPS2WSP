#ifndef OOP244_TOOLS_H
#define OOP244_TOOLS_H

#include "Persons.h"

//Function to check for uique socialid
bool checkSocialID(const std::string& sid, Person* persons[], int size);

bool checkAccountNumber(const std::string& accNum, Person* persons[], int size);

template<typename T>
void customSwap(T& a, T& b)
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
				customSwap(arr[j], arr[j + 1]);
			}
		}
	}
}
//Templates are in header file to not instiatiate.


void getInput(Person** persons, int numPersons);

//Comparison for each field 
bool compareByName(Person* a, Person* b);
bool compareBySocialID(Person* a, Person* b);
bool compareByAccountNumber(Person* a, Person* b);
bool compareByCreditLimit(Person* a, Person* b);
bool compareByCreditBalance(Person* a, Person* b);


#endif // !OOP244_TOOLS_H
