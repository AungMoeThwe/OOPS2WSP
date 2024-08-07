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
#include <iostream>
#include "Line.h"


using namespace std;

namespace seneca {
	Line::Line(const char* _label, int _length) : LblShape(_label)
	{
		if (_length > 0)
		{
			m_length = _length;
		}
	}

	void Line::getSpecs(std::istream& is)
	{
		int _length;
		bool _exit = false;

		do
		{
			LblShape::getSpecs(is);

			is >> _length;

			if (!is)
			{
				is.clear();
				is.ignore(4000, '\n');
			}
			else
			{
				is.ignore();
				m_length = _length;
				_exit = true;
			}
		} while (!_exit);
	}

	void Line::draw(std::ostream& os) const
	{
		if (m_length> 0 && LblShape::label())
		{
			os << LblShape::label() << endl;
			os.width(m_length);
			os.fill('=');
			os << '=';
		}
	}

}
