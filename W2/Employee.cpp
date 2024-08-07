/*/////////////////////////////////////////////////////////////////////////
                        OOP244_ZFF LAB02
Full Name  :Aung Moe Thwe
Student ID#:148396237
Email      :amthwe@myseneca.ca
Section    :ZFF
Date       :5/23/2024

Declaration:
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace seneca {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& employee) {
      bool ok = false;
      char name[128];
      /* if reading of employee number, salay and name are successful
              allocate memory to the size of the name + 1
              and keep its address in the name of the Employee Reference

              copy the name into the newly allocated memroy

              make sure the "ok" flag is set to true
         end if
      */

      if (read(employee.m_empNo) && read(employee.m_salary) && read(name)) // if reading successful
      {
          employee.m_name = new char[strlen(name) + 1]; // allocated memory to size + 1

          strcpy(employee.m_name, name); // copied string into new memory
          ok = true; // setting flag

      }
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i = 0; // for counter in loops
      int j = 0; // for counter in validation of employee records
      if (openFile(DATAFILE)) {
         /* 
          Set the noOfEmployees to the number of recoreds in the file.
          dyanamically allocated an array of employees into the global
          Employee pointer; "employees" to the size of the noOfEmployees.

          In a loop load the employee records from the file into 
          the dynamic array.

          If the number of the records does not match the number of reads
             print the message
            "Error: incorrect number of records read; the data is possibly corrupted"
          Otherwise
             set the ok flag to true
          End if

          close the file
          
         */
          noOfEmployees = noOfRecords(); //sets noOfEmployees to num of records

          employees = new Employee[noOfEmployees]; //dynamically allocating array of emplotes into global pointer

          for (i = 0; i < noOfEmployees; i++) // looping the records, loading the array and counting to check if its correct
          {
              if (load(employees[i]))
              {
                  j++;
              }
          }

          if (j != noOfEmployees) // if records dont martch, display error message
          {
              cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
          }
          else // sets flag to true otherwise
          {
              ok = true; 
          }

          closeFile();


      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(const Employee& employee)
   {
       cout << employee.m_empNo << ": " << employee.m_name << ", " << employee.m_salary << endl;
   }

   void display()
   {
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;

       sort();

       for (int i = 0; i < noOfEmployees; i++)
       {
           cout << i + 1 << "- ";
           display(employees[i]);
       }
   }


   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory()
   {
       for (int i = 0; i < noOfEmployees; i++)
       {
           delete[] employees[i].m_name;
       }
       delete[] employees;
   }
}