#include <iostream>

class ClassA
{
public:
    int *data;

    ClassA(int value) : data(new int(value)) {}

    ~ClassA()
    {
        std::cout << "Destructor called" << std::endl;
        delete data;
    }
};

int main()
{
    ClassA *obj1 = new ClassA(42); // obj1 owns the memory for the integer 42
    ClassA obj2 = *obj1;           // This will cause a shallow copy, both obj1 and obj2 point to the same memory

    std::cout << "obj1 data: " << *obj1->data << std::endl; // Output: 42
    std::cout << "obj2 data: " << *obj2.data << std::endl;  // Output: 42

    delete obj1; // This will free the memory, but obj2 still points to it, leading to a dangling pointer

    std::cout << "After deleting obj1:" << std::endl;
    // Accessing obj2's data now leads to undefined behavior since it points to memory that has been freed
    std::cout << "obj2 data: " << *obj2.data << std::endl; // This is unsafe and can cause a crash or garbage output

    // When main ends, both obj1 and obj2 will try to delete the same memory, causing undefined behavior (double deletion)
    return 0;
}