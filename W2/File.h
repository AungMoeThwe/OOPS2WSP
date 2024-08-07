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

#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_
namespace seneca {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes

   bool read(char* employeeNames); // first read overload. @param: address of character array

   bool read(int& emplployeeNumber); // second read overload. @param: reference of integer

   bool read(double& employeeSalary); // third read overload. @param: reference of floating point 
}
#endif // !SENECA_FILE_H_
