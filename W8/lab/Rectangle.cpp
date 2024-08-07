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

#define CRT_SECURE_NO_WARNINGS
#include "Rectangle.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace seneca {
	Rectangle::Rectangle(const char* _label, int _width, int _height) : LblShape(_label)
	{
		int widthCheck = strlen(LblShape::label()) + 2; // this is to convert size_t to integer to compare
		if (_width > widthCheck && _height > 3)
		{
			m_width = _width;
			m_height = _height;
		}
		else {
			m_width = 0;
			m_height = 0;
		}
	}

	void Rectangle::getSpecs(std::istream& is)
	{
		int _width, _height;
		char _comma;
		bool _exit = false;

		do
		{
		LblShape::getSpecs(is);

			is >> _width >> _comma >> _height;
			if (!is)
			{
				is.clear();
				is.ignore(4000, '\n');
			}
			else
			{
				is.ignore();
				m_width = _width;
				m_height = _height;
				_exit = true;
			}
		} while (!_exit);
	}

	void Rectangle::draw(std::ostream& os) const
	{
		if (m_width > 0 && m_height > 0 && label())
		{
			//First Line
			os << '+';
			os.width( m_width - 2);
			os.fill('-');
			os << '-' << '+' << endl;

			//Second Line
			os << '|';
			os.width(m_width - 2);
			os.fill(' ');
			os << left << LblShape::label() << '|' << endl;

			//Next Consequent Lines
			for (unsigned int i = 0; i < (m_height - 3); i++) {
				os << '|';
				os.width(m_width - 2);
				os.fill(' ');
				os << ' ' << '|' << endl;
			}

			//Last Line
			os << '+';
			os.width(m_width - 2);
			os.fill('-');
			os << '-' << '+';

		}
	}

}
