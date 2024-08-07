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

#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H

#include "LblShape.h"

namespace seneca {
    // Inherits LblShape
    class Rectangle : public LblShape {
        //num of chars
        unsigned int m_width{ 0 };
        unsigned int m_height{ 0 };

    public:
        Rectangle() {};
        Rectangle(const char* _label, int _width, int _height); // 3 args constructor

        // override functions
        void getSpecs(std::istream& is) override;
        void draw(std::ostream& os) const override;
    };
}

#endif // SENECA_RECTANGLE_H
