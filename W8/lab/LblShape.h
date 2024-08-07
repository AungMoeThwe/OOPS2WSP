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

#ifndef SENECA_LBLSHAPE_H
#define SENECA_LBLSHAPE_H

#include "Shape.h" //Inherits abstract class from "Shape" / getSpecs function

namespace seneca {
    // Inherits "Shape"
    class LblShape : public Shape {
        char* m_label {nullptr}; // holds dynamically allocated label for shape

    protected:
        const char* label() const; // query function, returning unmodifiable value of m_label

    public:
        LblShape() {}; //default constructor
        LblShape(const char* _label); //copies Cstring to newly allocated memory
        virtual ~LblShape(); //Virtual Destructor

        // Deletes copy constructor and asssignment operator
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;

        //Override base class (Shape) virtual function
        void getSpecs(std::istream& is) override; //recheck
    };
}

#endif // SENECA_LBLSHAPE_H
