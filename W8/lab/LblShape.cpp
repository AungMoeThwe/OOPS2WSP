/*/////////////////////////////////////////////////////////////////////////
						OOP244_ZFF LAB08
Full Name  :Aung Moe Thwe
Student ID#:148396237
Email      :amthwe@myseneca.ca
Section    :ZFF
Date       :7/19/2024

Declaration:
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;

namespace seneca {

	const char* LblShape::label() const //query function
	{
		return m_label;
	}

	LblShape::LblShape(const char* _label)
	{
		if (_label && _label[0] != '\0')
		{
			m_label = new char[strlen(_label) + 1];
			strcpy(m_label, _label);
		}
	}

	LblShape::~LblShape() //Destructor
	{
		if (m_label)
		{
			delete[] m_label;
			m_label = nullptr;
		}
	}

	void LblShape::getSpecs(std::istream& is)
	{
		string _label;

		getline(is, _label, ','); // reads until ,

		delete[] m_label;
		m_label = new char[strlen(_label.c_str()) + 1]; // .c_str converts _label to const char*
		strcpy(m_label, _label.c_str());
	}

}
