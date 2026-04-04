#include <iostream>
#include <memory>

using namespace std;

class Weapon
{
public:
    Weapon()
    {
        cout << "Weapon created!" << endl;
    }
    ~Weapon()
    {
        cout << "Weapon destroyed!" << endl;
    }

    int damage = 100;
};

void upgradeWeapon(unique_ptr<Weapon> weapon)
{
    cout << "Upgrading weapon..." << endl;
    weapon->damage += 50;
    cout << "Weapon damage: " << weapon->damage << endl;
};

int main()
{
    unique_ptr<Weapon> myWeapon = make_unique<Weapon>();

    // we can't pass smart pointer to a function by value due to Exclusive ownership, so we need to use move semantics to transfer ownership of the smart pointer to the function
    upgradeWeapon(move(myWeapon));
    // Notice what's just happened in RAM : myWeapon never moved, moving gigabytes of memory is expensive, instead, move just has taken the pointer to memory out of myWeapon and passed it to the function, so now myWeapon is empty and doesn't point to any memory, while the function has the ownership of the memory that myWeapon used to point to, and when the function ends, the destructor of Weapon will be called and the memory will be freed.

    if (myWeapon == nullptr)
    {
        cout << "myWeapon is now nullptr after being moved." << endl;
    }

    return 0;
}