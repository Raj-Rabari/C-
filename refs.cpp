#include <iostream>

using namespace std;

void upgradeWithPointer(int *damage)
{
    cout << "Upgrading weapon with pointer..." << endl;
    if (damage != nullptr)
    {
        *damage += 50;
        cout << "Weapon damage: " << *damage << endl;
    }
    else
    {
        cout << "Damage pointer is null!" << endl;
    }
}

void upgradeWithReference(int &damage)
{
    cout << "Upgrading weapon with reference..." << endl;
    damage += 50;
    cout << "Weapon damage: " << damage << endl;
}

int main()
{
    int weaponDamage = 100;

    // Using pointer
    upgradeWithPointer(&weaponDamage); // Pass the address of weaponDamage to the function

    // Using reference
    upgradeWithReference(weaponDamage); // Pass weaponDamage by reference to the function, pass the normal variable without using & operator, the function will automatically treat it as a reference

    return 0;
}