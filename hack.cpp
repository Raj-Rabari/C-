#include <iostream>
using namespace std;

void tryToHack(int accountBalance)
{
    accountBalance = 0;
    cout << "Hacked! Your account balance is now: " << accountBalance << endl;
}

void hack(int *accountBalance)
{
    *accountBalance = 0;
    cout << "Hacked! Your account balance is now: " << *accountBalance << endl;
}

int main()
{
    int accountBalance = 1000;
    int *ptr = &accountBalance;

    cout << "Original account balance: " << accountBalance << endl;
    tryToHack(accountBalance);
    cout << "Account balance after tryToHack: " << accountBalance << endl;

    cout << "Now trying to hack using pointer..." << endl;
    hack(ptr);
    cout << "Account balance after hack: " << accountBalance << endl;

    return 0;
}