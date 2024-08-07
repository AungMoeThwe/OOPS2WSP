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
#include <cstdio>
#include "File.h"

namespace seneca {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   } // data file reading 
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   } // num of records in the file

   void closeFile() {
      if (fptr) fclose(fptr);
   } // closes file

   // TODO: read functions go here
   bool read(char* employeeNames) {
       return fscanf(fptr, "%[^\n]\n", employeeNames) == 1;
   } // first read function returning true if it successfully reads the character array, false if not
   bool read(int& emplployeeNumber) {
       return fscanf(fptr, "%d,", &emplployeeNumber) == 1;
   } // second read function returning true if it successfully reads the integer, false if not
   bool read(double& employeeSalary) {
       return fscanf(fptr, "%lf,", &employeeSalary) == 1;
   } // third read function returning true if it successfully reads the floating point values, false if not
}