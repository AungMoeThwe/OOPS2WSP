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

#include <iostream>
#include "Shape.h"

namespace seneca {
    std::ostream& operator<<(std::ostream& os, const Shape& src) {
        src.draw(os);
        return os;
    }

    std::istream& operator>>(std::istream& is, Shape& src) {
        src.getSpecs(is);
        return is;
    }
}
