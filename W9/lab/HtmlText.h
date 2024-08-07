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

#ifndef SENECA_HTMLTEXT_H__
#define SENECA_HTMLTEXT_H__
#include "Text.h"
namespace seneca {
   class HtmlText :  public Text {
       char* m_title{nullptr};
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);

      // Rule of Three
      HtmlText(const HtmlText& H);
      HtmlText& operator=(const HtmlText& H);
      ~HtmlText();

      void write(std::ostream& os)const;
   };
}
#endif // !SENECA_HTMLTEXT_H__
