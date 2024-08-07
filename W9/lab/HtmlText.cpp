/*/////////////////////////////////////////////////////////////////////////
						OOP244_ZFF LAB09
Full Name  :Aung Moe Thwe
Student ID#:148396237
Email      :amthwe@myseneca.ca
Section    :ZFF
Date       :7/21/2024

Declaration:
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "HtmlText.h"
namespace seneca {
	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
		if (title != nullptr) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
	}

	HtmlText::HtmlText(const HtmlText& H) {
		*this = H;
	}

	HtmlText& HtmlText::operator=(const HtmlText& H) {
		if (this != &H) {
			(Text&)*this = H; // copying of parts using the base class

			if (m_title) delete[] m_title;
			if (H.m_title) {
				m_title = new char[strlen(H.m_title) + 1];
				strcpy(m_title, H.m_title);
			}
			else {
				m_title = nullptr;
			}
		}
		return *this;
	}

	HtmlText::~HtmlText() {
		if (m_title)
		{
			delete[] m_title;
			m_title = nullptr;
		}
	}

	void HtmlText::write(std::ostream& os) const {
		bool MS = false;
		char temp;

		os << "<html><head><title>";
		if (m_title != nullptr)
		{
			os << m_title;
		}
		else
		{
			os << "No Title";
		}

		os << "</title></head>\n<body>\n";

		if (m_title!=nullptr)
		{
			int i = 0;
			os << "<h1>" << m_title << "</h1>\n";
			while (Text::operator[](i) != '\0')
			{
				temp = Text::operator[](i);
				switch (temp)
				{
					case ' ':
					if (MS)
					{
						os << "&nbsp;";
						
					}
					else
					{
						os << temp;
						MS = true;
					}
					break;
					case '<':
						os << "&lt;";
						MS = false;
						break;
					case '>':
						os << "&gt;";
						MS = false;
						break;
					case '\n':
						os << "<br />\n";
						MS = false;
						break;
					default:
						MS = false;
						os << temp;
						break;
				}
				i++;
			}
		}
		os << "</body>\n</html>";
		
	}

}