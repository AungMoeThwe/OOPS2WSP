/*/////////////////////////////////////////////////////////////////////////
                        OOP244_ZFF LAB07
Full Name  :Aung Moe Thwe
Student ID#:148396237
Email      :amthwe@myseneca.ca
Section    :ZFF
Date       :7/12/2024

Declaration:
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

#include <iostream>

namespace seneca {

    class MotorVehicle {
    private:
        char m_licensePlate[9]{ '\0' };
        char m_address[64]{ '\0' };
        int m_yearBuilt{ 0 };

    public:
        // Constructors and Destructors
        MotorVehicle() {}
        MotorVehicle(const char* _licensePlate, int _year, const char* _location = "Factory");
        ~MotorVehicle() {}

        // moving to new address
        void moveTo(const char* _address);

        // Display Information and Take in Information
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
    };

    std::ostream& operator<<(std::ostream& os, const MotorVehicle& mv);
    std::istream& operator>>(std::istream& in, MotorVehicle& mv);

}

#endif // MOTORVEHICLE_H
