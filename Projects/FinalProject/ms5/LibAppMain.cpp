// Final Project
// Library Application Tester
// File  LibAppMain.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//Aung Moe Thwe      8/7/2024               MS5 
/////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include "LibApp.h"
#include "Date.h"
#include "Menu.h"
using namespace seneca;
void runApp(const char* filename) {
   size_t i{};
   char ch;
   char original[31] = "orig";
   // creating original file name
   while(filename[i]) { 
     original[4u + i] = filename[i];
     i++;
   }
   original[4u + i] = char(0);
   // copiying original values to data file;
   std::ofstream outFile(filename);
   std::ifstream inFile(original);
   while(inFile.get(ch)) {
      outFile << ch;
   }
   outFile.close();
   inFile.close();
   // setting test values
   seneca::seneca_day = 13;
   seneca::seneca_mon = 8;
   seneca::seneca_year = 2024;
   seneca::seneca_test = true;
   seneca::LibApp app(filename);
   app.run();
   std::cout << "Content of " << filename << "\n=========>\n";
   inFile.open(filename);
   while(inFile.get(ch)) std::cout << ch;
   std::cout << "<=========\n";
}
int main() {
   Menu outFile("Select Data File");
   outFile << "LibRecsSmall.txt" << "LibRecs.txt";
   switch(outFile.run()) {
   case 1:
      std::cout << "Test started using small data: " << std::endl;
      runApp("LibRecsSmall.txt");
      break;
   case 2:
      std::cout << "Test started using big data: " << std::endl;
      runApp("LibRecs.txt");
      break;
   default:
      std::cout << "Aborted by user! " << std::endl;
      break;
   }
   return 0;
}
