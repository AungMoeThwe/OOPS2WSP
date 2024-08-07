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

#include "Truck.h"

namespace seneca {

    Truck::Truck(const char* _plate, int _year, double _capacity, const char* _address)
        : MotorVehicle(_plate, _year), m_capacity(_capacity), m_currentCargo(0.0)
    {
        if (_address)
        {
            this->moveTo(_address);
        }
    }

    bool Truck::addCargo(const double cargo)
    {
        bool flag = false;

        if (cargo > 0 && (m_currentCargo < m_capacity))
        {
            m_currentCargo += cargo;
            flag = true;
            if (m_currentCargo > m_capacity)
            {
                m_currentCargo = m_capacity;
            }
        }
        return flag;
    }

    bool Truck::unloadCargo()
    {
        bool flag = false;

        if (m_currentCargo > 0)
        {
            m_currentCargo = 0.0;
            flag = true;
        }

        return flag;
    }

    std::ostream& Truck::write(std::ostream& os) const
    {
        MotorVehicle::write(os);
        os << " | " << m_currentCargo << "/" << m_capacity;
        return os;
    }

    std::istream& Truck::read(std::istream& in)
    {
        MotorVehicle::read(in);

        std::cout << "Capacity: ";
        in >> m_capacity;
        while (!in)
        {
            in.clear();
            in.ignore(40000, '\n');
            std::cout << "Invalid Max Capacity, Retry to enter: ";
            in >> m_capacity;
        }

        std::cout << "Cargo: ";
        in >> m_currentCargo;
        while (!in)
        {
            in.clear();
            in.ignore(40000, '\n');
            std::cout << "Invalid cargo amount, Retry to enter: ";
            in >> m_currentCargo;
        }

        return in;
    }

    std::ostream& operator<<(std::ostream& os, const Truck& truck)
    {
        return truck.write(os);
    }

    std::istream& operator>>(std::istream& in, Truck& truck)
    {
        return truck.read(in);
    }
}
