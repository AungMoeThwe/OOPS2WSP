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

#ifndef TRUCK_H
#define TRUCK_H

#include "MotorVehicle.h"

namespace seneca {

    class Truck : public MotorVehicle {
    private:
        double m_capacity{};
        double m_currentCargo{};

    public:
        Truck() {};
        Truck(const char* _plate, int _year, double _capacity, const char* address = nullptr);
        ~Truck() {};

        bool addCargo(const double cargo);
        bool unloadCargo();

        // Information display and take in
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
    };

    std::ostream& operator<<(std::ostream& os, const Truck& truck);
    std::istream& operator>>(std::istream& in, Truck& truck);

}

#endif // TRUCK_H
