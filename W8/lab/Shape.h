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

#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_SHAPE_H
#define SENECA_SHAPE_H

#include <iostream>

namespace seneca {
    class Shape {
    public:
        // Pure Virtual Functions. Prototype (=0), making class an interface that cant be instantiated
        virtual void draw(std::ostream& os) const = 0;
        virtual void getSpecs(std::istream& is) = 0;

        //Default Virtual Destructor. Gurantees any dynamically allocated derived class from this interface pointed by this pointer will be removed properly
        virtual ~Shape() = default;
    };

    std::ostream& operator<<(std::ostream& os, const Shape& src);
    std::istream& operator>>(std::istream& is, Shape& src);
}

#endif // SENECA_SHAPE_H
