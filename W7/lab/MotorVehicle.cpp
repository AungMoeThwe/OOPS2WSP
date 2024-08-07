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

#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
#include <cstring>

namespace seneca {
    MotorVehicle::MotorVehicle(const char* _licensePlate, int _year, const char* _location)
    {
        if (_licensePlate)
        {
            strncpy(m_licensePlate, _licensePlate, sizeof(m_licensePlate) - 1);
            m_licensePlate[sizeof(m_licensePlate) - 1] = '\0';
            m_yearBuilt = _year;
            if (_location) {
                strncpy(m_address, _location, sizeof(m_address) - 1);
                m_address[sizeof(m_address) - 1] = '\0';
            }
        }
    }

    void MotorVehicle::moveTo(const char* _address)
    {
        if (strcmp(m_address, _address) != 0)
        {
            std::cout << "|";
            std::cout.width(8);
            std::cout << m_licensePlate << "| |";

            std::cout.width(20);
            std::cout << m_address << " ---> ";

            std::cout.width(20);
            std::cout << std::left << _address << "|" << std::right << std::endl;

            strncpy(m_address, _address, sizeof(m_address) - 1);
            m_address[sizeof(m_address) - 1] = '\0';
        }
    }

    std::ostream& MotorVehicle::write(std::ostream& os) const
    {
        os << "|";
        os.width(5);
        os << m_yearBuilt << " | " << m_licensePlate << " | " << m_address;
        return os;
    }

    std::istream& MotorVehicle::read(std::istream& in)
    {
        std::cout << "Built year: ";
        in >> m_yearBuilt;
        while (!in)
        {
            in.clear();
            in.ignore(4000, '\n');
            std::cout << "Invalid year, Retry to enter: ";
            in >> m_yearBuilt;
        }

        std::cout << "License plate: ";
        in >> m_licensePlate;
        while (!in)
        {
            in.clear();
            in.ignore(4000, '\n');
            std::cout << "Invalid license plate, Retry to enter: ";
            in >> m_licensePlate;
        }

        std::cout << "Current location: ";
        in >> m_address;
        while (!in)
        {
            in.clear();
            in.ignore(4000, '\n');
            std::cout << "Invalid address, Retry to enter: ";
            in >> m_address;
        }

        return in;
    }

    std::ostream& operator<<(std::ostream& os, const MotorVehicle& mv)
    {
        return mv.write(os);
    }

    std::istream& operator>>(std::istream& in, MotorVehicle& mv)
    {
        return mv.read(in);
    }
}
