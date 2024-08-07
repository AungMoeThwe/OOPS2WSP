/*/////////////////////////////////////////////////////////////////////////
                        OOP244_ZFF LAB10
Full Name  :Aung Moe Thwe
Student ID#:148396237
Email      :amthwe@myseneca.ca
Section    :ZFF
Date       :7/31/2024

Declaration:
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_SEARCHNLIST_H
#define SENECA_SENECALIST_H

#include <iostream>
#include "Collection.h"

/*

----------------------------Template Types----------------------------

* The search function template
     *
     * Requirements:
     * - CollectionType (T1): Must support the `add` method to add elements to the collection.
     * - ArrayType (T1): Must support comparison with the key using the `==` operator.
     * - KeyType (T2): Must be comparable with the elements of the array using the `==` operator.
     *
     * Parameters:
     * - collection: A reference to a Collection of T1 objects where matched elements will be added.
     * - array: A pointer to an array of T1 objects to be searched.
     * - size: The number of elements in the array.
     * - key: The key of type T2 to search for in the array.
     *
     * Returns:
     * - true if at least one match is found; otherwise, false.
     * 
     * Description:
     * This template class can receive Car, Student, or Employee objects and search for a specific key in the array of objects. If a match is found, the object is added to the collection. The function returns true if at least one match is found; otherwise, it returns false.

* The listArrayElements function template
    *
    * Requirements:
    * - ArrayType: Must support insertion into an output stream using the `<<` operator.
    *
    * Parameters:
    * - title: A const char* representing the title to be printed before listing the array elements.
    * - array: A pointer to a constant array of ArrayType objects to be listed.
    * - size: The number of elements in the array.
    *
    * Functionality:
    * - Prints the title followed by a newline.
    * - Iterates through the array, printing each element's index (1-based) followed by the element itself, each on a new line.
    * 
    * Description:
    * This template function can receive an array of Car, Student, or Employee objects and list all the elements in the array. It prints the title followed by a newline and then iterates through the array, printing each element's index and the element itself on a new line.

*/


namespace seneca {

    /*
    * T1 - supporting the 'add' method is neccessary because the functions need to add them to the collection. Supporting comparison with the '==' is also needed to compare each element in the array to the key to see if they match.
    * T2 - This makes sure that the function can identify matching elements in the array based on the key provided.
     */
    template <typename T1, typename T2>
    bool search(Collection<T1>& collection, T1* array, int size, const T2& key) {
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (array[i] == key) {
                collection.add(array[i]);
                found = true;
            }
        }
        return found;
    }

    /*
    ArrayType - It is required for the function to print each element in the array.
    */
    template <typename ArrayType>
    void listArrayElements(const char* title, const ArrayType* array, int size) {
        std::cout << title << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << (i + 1) << ": " << array[i] << std::endl;
        }
    }

}

#endif // !SENECA_SEARCHNLIST_H
