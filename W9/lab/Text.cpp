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
#include <fstream>
#include <cstring>
#include "Text.h"

using namespace std;
namespace seneca {
   int Text::getFileLength() const {
	  int len = 0;
	  ifstream fin(m_filename);
	  while (fin) {
		 fin.get();
		 len += !!fin;
	  }
	  return len;
   }

   const char& Text::operator[](int index) const
   {
	   if (index >= 0 || index < getFileLength())
	   {
		   return m_content[index];
	   }
	   else // out of scope index
	   {
		   return m_content[getFileLength()];
	   }
   }

   Text::Text(const char* filename) : m_filename(nullptr), m_content(nullptr)
   {
	   if (filename != nullptr)
	   {
		   m_filename = new char[strlen(filename) + 1];
		   strcpy(m_filename, filename);
		   read();
	   }

   }

   Text::Text(const Text& T)
   {
	   *this = T;
   }

   Text& Text::operator=(const Text& T) 
   {
	   if (this != &T)
	   {
		   if (m_filename)
		   {
			   delete[] m_filename;
		   }

		   if (T.m_filename)
		   {
			   m_filename = new char[strlen(T.m_filename) + 1];
			   strcpy(m_filename, T.m_filename);
			   read();
		   }
	   }
	   else
	   {
		   m_filename = nullptr;
		   m_content = nullptr;
	   }
	   return *this;
   }
   
   Text::~Text() 
   {
	   if (m_filename)
	   {
		   delete[] m_filename;
		   m_filename = nullptr;
	   }

	   if (m_content)
	   {
		   delete[] m_content;
		   m_content = nullptr;
	   }
   }

   void Text::read()
   {
	   char temp;
	   int i = 0;

	   ifstream file(m_filename);

	   if (m_content) delete[] m_content;

	   if (file.is_open())
	   {
		   m_content = new char[getFileLength() + 1];
		   while (file.get(temp))
		   {
			   m_content[i] = temp;
			   i++;
		   }

		   m_content[i] = '\0';
	   }
	   else
	   {
		   m_content = nullptr;
	   }
	   

   }

   void Text::write(std::ostream& os) const
   {
	   if (m_content != nullptr)
	   {
		   os << m_content;
	   }
   }

   std::ostream& operator<<(std::ostream& os, const Text& T)
   {
	  T.write(os);
	  return os;
   }


}