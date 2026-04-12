/*
    Rule of Five in C++
    The Rule of Five states that if your class needs custom destructor to clean up memory, it almost needs you to explicitly write out other four memory managment functions to prevent shallow copy crashes.
    it should define all five:
    1. Destructor: To free the heap
    2. Copy constructor : To deep copy when an object born from an lvalue
    3. Copy assignment operator: to deep copy into an object that already exist.
    4. Move constructor: to steal the pointer when object is born from an rvalue.
    5. Move assignment operator: to steal the pointer into an object that already exist.
*/

/**
 * Rule of Zero:
 *  If you strictly use smart pointers and stl containers, you can avoid writing all five of these functions because the compiler automattically uses it's built in rules for smart pointers to safely copy or  move your classes with zero memory leak.
 */

#include <iostream>
#include <algorithm>

class SmartArray
{
private:
    int *data;
    size_t size;

public:
    // Standard constructor to allocate memory
    SmartArray(size_t size) : size(size)
    {
        data = new int[size];
        std::cout << "[Constructor] Allocated " << size << "Items on the heap" << std::endl;
        std::fill(data, data + size, 0); // Initialize with zeros
    }

    ~SmartArray()
    {
        delete[] data; // Free the allocated memory
        std::cout << "[Destructor] Memory freed for SmartArray" << std::endl;
    }

    // copy constructor takes lvalue
    // triggered by SmartArray arr2 = arr1; or SmartArray arr2(arr1);
    SmartArray(const SmartArray &other) : size(other.size)
    {
        std::cout << "[Copy Constructor] Deep copying from another SmartArray" << std::endl;
        data = new int[size]; // Allocate new memory
        std::copy(other.data, other.data + size, data);
    }

    // move constructor takes rvalue
    // triggered by SmartArray arr2 = std::move(arr1); or SmartArray arr2(std::move(arr1));
    SmartArray(SmartArray &&other) noexcept : data(other.data), size(other.size)
    {
        std::cout << "[Move constructor] stealing the pointer! " << std::endl;
        other.data = nullptr; // Set the source's pointer to null to prevent double deletion
        other.size = 0;       // Optional: reset size to indicate it's empty
    }

    // copy assignment operator
    // triggered by arr2 = arr1; where arr2 already exist
    SmartArray &operator=(const SmartArray &other)
    {
        std::cout << "[Copy Assignment Operator] Deep copying into an existing SmartArray" << std::endl;

        if (this == &other)
        {
            return *this; // Handle self-assignment
        }

        delete[] data; // free existing memory

        size = other.size;
        data = new int[size]; // Allocate new memory
        std::copy(other.data, other.data + size, data);
        return *this;
    }

    // move Assignment operator
    // triggered by arr2 = std::move(arr1); where arr2 already exist
    SmartArray &operator=(SmartArray &&other) noexcept
    {
        std::cout << "[Move Assignment Operator] stealing the pointer into an existing SmartArray" << std::endl;

        if (this == &other)
        {
            return *this; // Handle self-assignment
        }

        delete[] data;        // free existing memory
        data = other.data;    // Steal the pointer
        size = other.size;    // Steal the size
        other.data = nullptr; // Set the source's pointer to null to prevent double deletion
        other.size = 0;       // Optional: reset size to indicate it's empty
        return *this;
    }
};

int main()
{
    std::cout << "Creating SmartArray arr1 with size 5" << std::endl;
    SmartArray arr1(5); // Constructor

    std::cout << "\nCopying arr1 to arr2 using copy constructor" << std::endl;
    SmartArray arr2 = arr1; // Copy constructor

    std::cout << "\nMoving arr1 to arr3 using move constructor" << std::endl;
    SmartArray arr3 = std::move(arr1); // Move constructor

    std::cout << "\nAssigning arr2 to arr4 using copy assignment operator" << std::endl;
    SmartArray arr4(5); // Constructor
    arr4 = arr2;        // Copy assignment operator

    std::cout << "\nMoving arr3 to arr5 using move assignment operator" << std::endl;
    SmartArray arr5(5);     // Constructor
    arr5 = std::move(arr3); // Move assignment operator

    return 0;
}