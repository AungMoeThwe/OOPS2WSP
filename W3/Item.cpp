/*/////////////////////////////////////////////////////////////////////////
						OOP244_ZFF LAB03
Full Name  :Aung Moe Thwe
Student ID#:148396237
Email      :amthwe@myseneca.ca
Section    :ZFF
Date       :5/31/2024

Declaration:
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Item.h"

const double TAXRATE = 0.13;

using namespace std;
namespace seneca {
	
	void Item::setName(const char* name) {
		if (name)
		{
			strncpy(m_itemName, name, 20);
			m_itemName[20] = '\0';
		}
		else
		{
			setEmpty();
		}
		
	}

	void Item::setEmpty()
	{
		m_price = 0.0;
		*m_itemName = '\0';
		
	}

	void Item::set(const char* name, double price, bool taxed)
	{

		if (name != nullptr && price > 0)
		{
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	double Item::price()const {

		return m_price;
	}

	double Item::tax() const {
		if (m_taxed) {
			return m_price * TAXRATE;
		}
		else {
			return 0.0;
		}
	}

	bool Item::isValid()const {
		if (*m_itemName != '\0' && m_price >= 0.0) {
			return true;
		}
		else
		{
			return false;
		}

	}

	void Item::display()const {
		if (isValid())
		{
			char dots = cout.fill('.');
			cout << "| ";
			cout.setf(ios::left);
			cout.width(20);
			cout << m_itemName;
			cout.fill(dots);
			cout.unsetf(ios::left);

			cout << " | ";
			cout.width(7);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_price;
			cout.unsetf(ios::fixed);

			if (m_taxed)
			{
				cout << " | Yes |" << endl;

			}
			else
			{
				cout << " | No  |" << endl;
			}
			 

		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << std::endl;
		}
	
	}

}
