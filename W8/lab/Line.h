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

#ifndef SENECA_LINE_H
#define SENECA_LINE_H

#include "LblShape.h" 

namespace seneca {
    //Inherits LblShape class
    class Line : public LblShape {
        unsigned int m_length{ 0 };

    public:
        Line() {};
        Line(const char* _label, int _length); // 2 args constructor. passes Cstr constructor to base class. sets m_length

        //overrides the base class virtual funcs
        void getSpecs(std::istream& is) override;
        void draw(std::ostream& os) const override;
        
    };
}

#endif // SENECA_LINE_H
