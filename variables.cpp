#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    char b = 'A';
    double salary = 50000.50;

    cout << "=========== Size in Memory ============>" << endl;
    cout << "Size of int: " << sizeof(a) << " bytes" << endl;
    cout << "size of char: " << sizeof(b) << " bytes" << endl;
    cout << "Size of double: " << sizeof(salary) << " bytes" << endl;

    cout << "============ Memory addressess =============" << endl;
    cout << "Adresss of a: " << &a << endl;
    cout << "Address of b: " << (void *)(&b) << endl;
    cout << "Address of salary: " << &salary << endl;

    return 0;
}