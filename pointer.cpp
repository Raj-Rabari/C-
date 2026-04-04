#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int *ptr = &a;

    cout << "value of a noramlly: " << a << endl;
    cout << "address of a using & operator: " << &a << endl;
    cout << "value of a using pointer: " << *ptr << endl;
    cout << "address of a using pointer: " << ptr << endl;

    return 0;
}