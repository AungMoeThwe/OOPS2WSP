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
#include "Bill.h"
using namespace std;
namespace seneca {
	void Bill::setEmpty() {
		*m_title = '\0';
		m_items = nullptr;
		m_noOfItems = 0;
		m_itemsAdded = 0;
	}

	bool Bill::isValid()const {
		bool flag = true;
		if (*m_title == '\0' || m_items == nullptr)
		{
			return false;
		}
		for (int i = 0; i < m_noOfItems && flag; i++)
		{
			if (!m_items[i].isValid())
			{
				return false;
			}
		}
		return true;
		
	}

	double Bill::totalTax()const {
		double taxSum = 0.0;
		for (int i = 0; i < m_noOfItems; i++)
		{
			taxSum += m_items[i].tax();
		}
		return taxSum;
	}

	double Bill::totalPrice()const {
	
		double priceSum = 0.0;
		for (int i = 0; i < m_noOfItems; i++)
		{
			priceSum += m_items[i].price();

		}
		return priceSum;
	}

	void Bill::Title()const {
		cout << "+--------------------------------------+" << endl;
		if (isValid())
		{
			cout << "| ";
			cout.setf(ios::left);
			cout.width(36);
			cout << m_title << " |" << endl;
			cout.unsetf(ios::left);

		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer() const
	{
		cout << "+----------------------+---------+-----+" << endl;

		if (isValid()) 
		{
			double tax = totalTax();
			double price = totalPrice();
			double finalValue = tax + price;

			cout.setf(ios::fixed);
			cout.precision(2);

			cout << "|                Total Tax: ";
			cout.width(10);
			cout << tax;
			cout << " |" << endl;

			cout << "|              Total Price: ";
			cout.width(10);
			cout << price;
			cout << " |" << endl;

			cout << "|          Total After Tax: ";
			cout.width(10);
			cout << finalValue; 
			cout << " |" << endl;
			cout.unsetf(ios::fixed);
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
			
		}
		cout << "+--------------------------------------+" << endl;

	}

	void Bill::init(const char* title, int noOfItems) {
		if (title == nullptr || noOfItems < 0  )
		{
			setEmpty();
		}
		else
		{
			strncpy(m_title, title, 36);
			m_title[36] = '\0';

			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			
			m_items = new Item[noOfItems];

			for (int i = 0; i < noOfItems; i++)
			{
				m_items[i].setEmpty();
			}
		}
	}
	

	

	bool Bill::add(const char* item_name, double price, bool taxed){
		if (m_itemsAdded < m_noOfItems)
		{
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			return true;
		}
		else
		{
			return false;
		}
	
	}



	void Bill::display()const{
	
		Title();
		for (int i = 0; i < m_noOfItems; i++)
		{
			m_items[i].display();
		}
		footer();
	}




	void Bill::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}
}

