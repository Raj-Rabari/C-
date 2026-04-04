#include <iostream>

using namespace std;

class Player
{
public:
    int health = 1000;
    char rank = 'A';
};

int main()
{
    Player p1; // instantiate a player object , Memory is allocated for p1 on the stack,

    // you can see below the address of p1 and health is same and address of rank is just 4 bytes after health because health is an int which takes 4 bytes in memory, and rank is a char which takes 1 byte in memory, so the total size of player object is 5 bytes, but due to padding and alignment, the actual size of player object is 8 bytes, because the compiler adds 3 bytes of padding after rank to align the next object on a 4-byte boundary.

    cout << "Player address: " << &p1 << endl;                   // print the address of p1 on the stack
    cout << "Player health address: " << &p1.health << endl;     // print the address of p1's health member variable
    cout << "Player rank address: " << (void *)&p1.rank << endl; // print
    cout << "Size of player object: " << sizeof(p1) << " bytes" << endl;

    return 0;
}
