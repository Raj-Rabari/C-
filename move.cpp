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

    if (myWeapon == nullptr)
    {
        cout << "myWeapon is now nullptr after being moved." << endl;
    }

    return 0;
}