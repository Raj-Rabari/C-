#include <iostream>

using namespace std;

/*
RAII: The Core of Modern C++
What you just wrote inside that Destructor is the most important design pattern in C++. It is called RAII (Resource Acquisition Is Initialization).

Remember the Smart Pointers (std::unique_ptr) we talked about earlier? They are not magic. A std::unique_ptr is literally just a tiny class written exactly like the Person class you just made.

In its Constructor, it takes a raw pointer.

In its Destructor, it calls delete on that pointer.

Because the Smart Pointer object itself lives on the Stack, C++ guarantees its Destructor will fire when the function ends. This guarantees the Heap memory is freed. You just learned how to build your own safe memory wrappers!
*/

class Person
{
public:
    string name;
    int *dynamicMemory;
    Person(string name)
    {
        this->name = name;
        cout << "Person " << name << " is born!" << endl;

        this->dynamicMemory = new int[10];
    }
    ~Person()
    {
        cout << "Person " << name << " is destroyed!" << endl;

        delete[] this->dynamicMemory;
    }
};

void createPerson()
{
    Person p("Alice"); // Memory for p is allocated on the stack, and the constructor is called to initialize p, so we see "Person Alice is born!" in the output
    // when the function ends, the destructor of Person will be called and the memory allocated for p will be freed, so we don't have to worry about memory leaks in this case, because the destructor takes care of it.
}

int main()
{
    createPerson(); // when this function is called, a Person object is created and destroyed within the scope of the function, so we see both the constructor and destructor messages in the output

    Person *p2 = new Person("Inside Heap"); // Memory for p2 is allocated on the heap, and the constructor is called to initialize p2, so we see "Person Inside Heap is born!" in the output
    // when we allocate memory on the heap, we have to manually free it using delete operator, otherwise we will have a memory leak, because the destructor will never be called for p2, so we need to call delete operator to free the memory allocated for p2, and when we do that, the destructor of Person will be called and we will see "Person Inside Heap is destroyed!" in the output
    delete p2;

    return 0;
}