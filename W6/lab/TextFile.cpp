/*/////////////////////////////////////////////////////////////////////////
                        OOP244_ZFF LAB06
Full Name  :Aung Moe Thwe
Student ID#:148396237
Email      :amthwe@myseneca.ca
Section    :ZFF
Date       :7/2/2024

Declaration:
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"
using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strlen(lineValue) + 1];
      strcpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
   }


   void TextFile::setFilename(const char* fname, bool isCopy)
   {
       
       if (isCopy)
       {
           delete[] m_filename;
           m_filename = new char[strlen(fname) + 3];
           strcpy(m_filename, "C_");
           strcat(m_filename, fname);
       }
       else
       {
           delete[] m_filename;
           m_filename = new char[strlen(fname) + 1];
           strcpy(m_filename, fname);
       }

   }

   void TextFile::setNoOfLines()
   {
       ifstream file(m_filename);
       m_noOfLines = 0;
       string temp;
       while (getline(file, temp)) { //diff review
           m_noOfLines++;
       }
       if (m_noOfLines ==0)
       {
           setEmpty();
       }
       else {
           m_noOfLines++;
       }
   }

   void TextFile::loadText()
   {

       if (m_filename != nullptr)
       {
           delete[] m_textLines;
           m_textLines = new Line[m_noOfLines];

           ifstream readLines(m_filename);

           string temp;
           unsigned i = 0;

           while (getline(readLines, temp))
           {
               m_textLines[i] = temp.c_str();

               i++;
           }
           m_noOfLines = i;
       }
   }

   void TextFile::saveAs(const char* fileName) const
   {
       ofstream file(fileName);
       if (file)
       {
           for (unsigned i = 0; i < m_noOfLines; i++)
           {
               file << (const char*)m_textLines[i] << endl;
           }
       }
       
   }

   void TextFile::setEmpty()
   {
       delete[] m_textLines;
       m_textLines = nullptr;
       delete[] m_filename;
       m_filename = nullptr;
       m_noOfLines = 0;
   }

   TextFile::TextFile(unsigned pageSize) : m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(pageSize){}

   TextFile::TextFile(const char* filename, unsigned pageSize) : m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(pageSize) {

       if (filename != nullptr)
       {
           setFilename(filename);
           setNoOfLines();
           loadText();

       }
       
   }

   TextFile::TextFile(const TextFile& other) :m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(other.m_pageSize)
   {
       
       if (other.m_filename != nullptr)
       {
           setFilename(other.m_filename, true);
           other.saveAs(m_filename);
           setNoOfLines();
           loadText();
       }
   }

   TextFile& TextFile::operator=(const TextFile& other) 
   {
       if (this != &other && *this && other)
       {
           delete[] m_textLines;
           m_textLines = nullptr;

           
           other.saveAs(m_filename);
           setNoOfLines();
           loadText();
       }
       return *this;
   }

   TextFile::~TextFile()
   {
       setEmpty();
   }


   std::ostream& TextFile::view(std::ostream& ostr) const //trying this method
   {
       if (*this)
       {
           ostr << m_filename << endl;
           ostr << string(strlen(m_filename), '=') << endl;
           for (unsigned i = 0; i < m_noOfLines; i++)
           {
               ostr << (const char*)m_textLines[i] << endl;
               if ((i+1)%m_pageSize ==0)
               {
                   ostr << "Hit ENTER to continue...";
                   cin.get();
                   cin.clear();
               }
           }

       }

       return ostr;
   }

   std::istream& TextFile::getFile(std::istream& istr)
   {
       string filename;
       istr >> filename;
       istr.clear();
       istr.ignore(1000, '\n');
       setFilename(filename.c_str());
       setNoOfLines();
       loadText();
       return istr;
   }

   TextFile::operator bool() const
   {
       bool flag;

       if (m_filename != nullptr && m_textLines != nullptr)
       {
           flag = true;
       }
       else
       {
           flag = false;
       }

       return flag;
   }

   unsigned TextFile::lines() const
   {
       return m_noOfLines;
   }

   const char* TextFile::name() const
   {
       return m_filename;
   }

   const char* TextFile::operator[](unsigned index) const
   {
       if (m_textLines != nullptr && m_noOfLines != 0)
       {
           return m_textLines[index % m_noOfLines];
       }
       else
       {
           return nullptr;
       }
   }

   

   std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
   {
       return text.view(ostr);
   }

   std::istream& operator>>(std::istream& istr, TextFile& text)
   {
       return text.getFile(istr);
   }


}