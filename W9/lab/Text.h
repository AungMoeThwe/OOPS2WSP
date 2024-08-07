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


#ifndef SENECA_TEXT_H__
#define SENECA_TEXT_H__
#include <iostream>

namespace seneca {
   class Text {
       char* m_filename{nullptr};
       char* m_content{nullptr};
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);

      // Rule of Three
      Text(const Text& T);
      Text& operator=(const Text& T);
      virtual ~Text();



      void read();
      virtual void write(std::ostream& os)const;
   };

   //Prototype insertion overload operator
   std::ostream& operator<<(std::ostream& os, const Text& T);

}
#endif // !SENECA_PERSON_H__

