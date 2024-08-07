/*/////////////////////////////////////////////////////////////////////////
                        OOP244_ZFF LAB04
Full Name  :Aung Moe Thwe
Student ID#:148396237
Email      :amthwe@myseneca.ca
Section    :ZFF
Date       :6/13/2024

Declaration:
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H
#include <iostream>

namespace seneca {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      ~Account() {};

      // TYPE CONVERSION OPERATORS
      operator bool() const; //state of account
      operator int() const; // account number
      operator double() const; // check money in account

      // UNARY member operators
      bool operator~() const; // check if acount is new and have an acc number

      //Binary Member operators
      Account& operator+=(const double deposit); // deposit if valid
      Account& operator-=(const double withdraw); // withdraw if valid
      Account& operator>>(Account& transferRight); // left to right transfer
      Account& operator<<(Account& transferLeft); // right to left transfer
      Account& operator=(const int accNum); //setting acc number
      Account& operator=(Account& moveData); //transferring acc data

      //Helper Functions
      friend double operator+(const Account& left, const Account& right); // total of two accounts
      friend double operator+=(double& value, const Account& add); // add balance to double value


   };
   
   
}
#endif // SENECA_ACCOUNT_H_