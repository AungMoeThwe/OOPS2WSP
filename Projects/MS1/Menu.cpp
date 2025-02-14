/* 
Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Aung Moe Thwe
Revision History
-----------------------------------------------------------
Date      Reason
2024/7/5  Preliminary release
2024/7/5  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <cstring>
#include <iostream>

using namespace std;
namespace seneca {

	MenuItem::MenuItem() : m_menuItem(nullptr) {}

	MenuItem::MenuItem(const char* item) { //check this
		if (item && item[0] != '\0') {
			m_menuItem = new char[strlen(item) + 1];
			strcpy(m_menuItem, item);
		}
		else {
			m_menuItem = nullptr;
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] m_menuItem;
	}

	MenuItem::operator bool() const //check this
	{
		return m_menuItem != nullptr && m_menuItem[0] != '\0';
	}

	MenuItem::operator const char* () const //this too
	{
		return m_menuItem;
	}

	void MenuItem::display(std::ostream& os) const {
		if (*this) {
			os << m_menuItem;
		}
	}

	Menu::Menu() : m_menuTitle(nullptr), m_numOfMenu(0) { //either this or just menutitle null and noofmenu 0
		for (int i = 0; i < MAX_MENU_ITEMS; ++i) {
			m_items[i] = nullptr;
		}
	}

	Menu::Menu(const char* title) : Menu()
	{
		if (title && title[0] != '\0')  {
			m_menuTitle = new char[strlen(title) + 1];
			strcpy(m_menuTitle, title);
		}
	}

	Menu::~Menu() {
		delete[] m_menuTitle;
		for (int i = 0; i < m_numOfMenu; ++i) {
			delete m_items[i];
		}
	}

	int Menu::run()
	{
		display();
		char choice;
		cin >> choice;
		int x = choice - '0';
		while (x < 0 || x > m_numOfMenu)
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "Invalid Selection, try again: ";
			cin >> choice;
			x = choice - '0';
		}
		return x;
	}

	void Menu::display()
	{
		if (m_menuTitle != nullptr)
		{
			cout << m_menuTitle << ":\n";
		}
		for (int i = 0; i < m_numOfMenu; i++)
		{
			cout << " " << i + 1 << "- " << m_items[i]->m_menuItem << endl;
		}
		cout << " 0- Exit\n> ";
	}

	char* Menu::operator[](int i) const
	{
		return m_items[i]->m_menuItem;
	}

	Menu::operator bool() const
	{
		if (m_menuTitle == nullptr)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	int Menu::operator~() //same as run function but overloaded
	{
		display();
		char choice;
		cin >> choice;
		int x = choice - '0';
		while (x < 0 || x > m_numOfMenu)
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "Invalid Selection, try again: ";
			cin >> choice;
			x = choice - '0';
		}
		return x;
	}

	std::ostream& Menu::write(std::ostream& os) const
	{
		if (m_menuTitle!=nullptr) {
			os << m_menuTitle;
		}
		return os;
	}

	Menu& Menu::operator<<(const char* menuContent) //adding menuItem to menu
	{
		if (m_numOfMenu < MAX_MENU_ITEMS) {
			m_items[m_numOfMenu++] = new MenuItem(menuContent);
			
		}
		return *this;
	}

	Menu::operator unsigned int() const
	{
		return m_numOfMenu;
	}

	


	std::ostream& operator<<(std::ostream& os, const Menu& m)
	{
		return m.write(os);
	}

}