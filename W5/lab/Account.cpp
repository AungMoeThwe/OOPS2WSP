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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999 && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   //TYPE CONVERSIONS
   Account::operator bool() const
   {
       return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
   }

   Account::operator int() const
   {
       return m_number;
   }

   Account::operator double() const
   {
       return m_balance;
   }

   // Unary Members
   bool Account::operator~() const
   {
       return m_number == 0;
   }

   //Binary Members

   // Assignment Operators
   Account& Account::operator=(Account& moveData)
   {
       if (m_number == 0 && moveData) {
           m_number = moveData.m_number;
           m_balance = moveData.m_balance;
           moveData.m_number = 0;
           moveData.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator=(const int accNum)
   {
       if (m_number == 0) {
           if (accNum >= 10000 && accNum <= 99999) {
               m_number = accNum;
           }
           else {
               setEmpty();
           }
       }
       return *this;
   }
   Account& Account::operator+=(const double deposit)
   {
       if (*this && deposit >= 0) {
           m_balance += deposit;
       }
       return *this;
   }

   Account& Account::operator-=(const double withdraw)
   {
       if (*this && withdraw >= 0 && m_balance >= withdraw) {
           m_balance -= withdraw;
       }
       return *this;
   }

   Account& Account::operator<<(Account& transferLeft)
   {

       if (this != &transferLeft && *this && transferLeft) {
           m_balance += transferLeft.m_balance;
           transferLeft.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator>>(Account& transferRight)
   {
       if (this != &transferRight && *this && transferRight) {
          transferRight.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;

   }


   //Helper Functions
   double operator+(const Account& left, const Account& right)
   {
       if (left && right) {
           return left.m_balance + right.m_balance;
       }
       return 0.0;
   }

   double operator+=(double& value, const Account& add)
   {
       if (add) {
           value += add.m_balance;
       }
       return value;
   }

}