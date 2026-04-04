#include <iostream>

using namespace std;

int main()
{
    int *ptr = new int;

    *ptr = 42;

    delete ptr; // if you forget to delete, it will cause memory leak and no progarm can use that memory again.
    return 0;
}