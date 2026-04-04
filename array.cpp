#include <iostream>

using namespace std;

int main()
{
    int arr[3] = {111, 12, 33};

    cout << "address of arr using & operator: " << &arr << endl;
    cout << "Now let's check what it stores inside the variable arr: " << arr << endl;

    cout << "Value at index 0: " << *arr << endl;
    cout << "Value at index 1: " << *(arr + 1) << endl;

    cout << "address of arr[1]: " << &arr[1] << endl;
    cout << "address of arr[1] using pointer arithmetic: " << (arr + 1) << endl;
    cout << "Value at index 1 using pointer arithmetic: " << *(arr + 1) << endl;

    return 0;
}