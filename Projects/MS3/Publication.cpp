/*
Citation and Sources...
Final Project Milestone 2
Module: Publication
Filename: Publication.cpp
Version 1.0
Author	Aung Moe Thwe
Revision History
-----------------------------------------------------------
Date      Reason
2024/7/23  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Publication.h"
#include <iostream>
#include <iomanip>
#include <cstring>

namespace seneca {
	Publication::Publication()
	{
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();
	}

	//Modifiers

	void Publication::set(int member_id)
	{
		m_membership = member_id;
	}

	void Publication::setRef(int value)
	{
		m_libRef = value;
	}

	void Publication::resetDate()
	{
		m_date = Date();
	}

	//Queries
	char Publication::type() const
	{
		return 'P';
	}

	bool Publication::onLoan() const
	{
		
		return (m_membership != 0);
	}

	Date Publication::checkoutDate() const
	{
		return m_date;
	}

	bool Publication::operator==(const char* title) const
	{
		return strstr(m_title, title) != nullptr;
	}

	Publication::operator const char* () const
	{
		return m_title;
	}

	int Publication::getRef() const
	{
		return m_libRef;
	}

	//Overrides
	bool Publication::conIO(std::ios& io) const
	{
		return &io == &std::cin || &io == &std::cout;
	}

	std::ostream& Publication::write(std::ostream& os) const
	{
		char temp[SENECA_TITLE_WIDTH + 1]{ 0 };
		std::strncpy(temp, m_title, SENECA_TITLE_WIDTH);

		if (conIO(os)) // LEFT JUSTIFIED WITH DOTS
		{
			os << "| " << m_shelfId << " | " << std::setw(30) << std::left <<
				std::setfill('.') << temp << " | ";
			(m_membership != 0) ? os << m_membership : os << " N/A ";
			os << " | " << m_date << " |";
		}
		else // TAB FORMAT
		{
			os << type();
			os << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
			(m_membership != 0) ? os << m_membership : os << " N/A ";
			os << "\t" << m_date;
		}
		return os;
	}

	std::istream& Publication::read(std::istream& istr)
	{
		char temp[256]{},
			shelfId[SENECA_SHELF_ID_LEN + 1]{};
		int libRef = -1, memberShip = 0;
		Date date;

		if (m_title)
		{
			delete[] m_title;
			m_title = nullptr;
		}

		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();

		if (conIO(istr))
		{
			std::cout << "Shelf No: ";
			istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1);
			if (strlen(shelfId) != SENECA_SHELF_ID_LEN)
			{
				istr.setstate(std::ios::failbit);
			}
			std::cout<< "Title: ";
			istr.getline(temp, 256);
			std::cout << "Date: ";
			istr >> date;
		}
		else
		{
			istr >> libRef;
			istr.ignore();
			istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1, '\t');
			istr.getline(temp, 256, '\t');
			istr >> memberShip;
			istr.ignore();
			istr >> date;
		}
		if (!date)
		{
			istr.setstate(std::ios::failbit);
		}
		if (istr)
		{
			m_title = new char[strlen(temp) + 1];
			strcpy(m_title, temp);
			strcpy(m_shelfId, shelfId);
			m_membership = memberShip;
			m_libRef = libRef;
			m_date = date;
		}
		return istr;

	}

	Publication::operator bool() const
	{
		bool flag = false;
		if (m_title != nullptr && m_shelfId[0] != '\0')
		{
			flag = true;
		}
		return flag;
	}


	// RULE OF THREE
	Publication::Publication(const Publication& p)
	{
		*this = p;
	}

	Publication& Publication::operator=(const Publication& p)
	{
		set(p.m_membership);
		setRef(p.m_libRef);
		strcpy(m_shelfId, p.m_shelfId);
		m_date = p.m_date;
		if (m_title)
		{
			delete[] m_title;
			m_title = nullptr;
		}
		if (p.m_title != nullptr)
		{
			m_title = new char[strlen(p.m_title) + 1];
			strcpy(m_title, p.m_title);
		}
		else
		{
			m_title = nullptr;
		}
		return *this;
	}

	Publication::~Publication()
	{
		delete[] m_title;
	}


	std::ostream& operator<<(std::ostream& os, const Publication& p)
	{
		if (p)
		{
			p.write(os);
		}
		return os;
	}

	std::istream& operator>>(std::istream& is, Publication& p)
	{
		return p.read(is);
	}

}

