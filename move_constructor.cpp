#include <iostream>
#include <string>
#include <vector>

class ClientDatabase
{
public:
    int *data; // Pointer to massive Heap memory

    // 1. The Old Copy Constructor (Takes an lvalue: const Type&)
    // Forces a slow, deep copy because the original needs to stay intact.
    ClientDatabase(const ClientDatabase &other)
    {
        data = new int[1000000]; // Allocate new memory
        // ... copy every single item over ...
    }

    // 2. The New Move Constructor (Takes an rvalue: Type&&)
    // Blazingly fast. It STEALS the pointer because 'other' is about to die!
    ClientDatabase(ClientDatabase &&dyingTempObject)
    {
        data = dyingTempObject.data;    // Steal the memory address!
        dyingTempObject.data = nullptr; // Set the dying object to null so its destructor doesn't delete our stolen memory
    }
};