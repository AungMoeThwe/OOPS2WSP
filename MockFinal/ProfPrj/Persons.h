#ifndef OOP244_PERSONS_H
#define OOP244_PERSONS_H

#include <iostream>
#include <string>

using namespace std;


class Person
{
	string name{};
	string socialID{};
	string accountNumber{};
	double creditLimit;
	double creditBalance;

public:
	//Constructors with arguments
	Person(const string& n = "", const string& sid = "", const string& accNum= "", double climit = 0.0, double cBalance = 0.0);

	//Rule of 3
	//Copy Constructor
	Person(const Person& p);
	// Copy Assignment
	Person& operator = (const Person& p);
	//Destructor
	~Person() = default;

	//Query functions
	string getName() const;
	string getSocialID() const;
	string getAccountNumber() const;
	double getCreditLimit() const;
	double getCreditBalance() const;

	//Display functions
	void display() const;
};




#endif // !OOP244_PERSONS_H