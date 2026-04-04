#include <iostream>
#include <memory>
using namespace std;

class Enemy
{
public:
    Enemy()
    {
        cout << "Enemy created!" << endl;
    }
    ~Enemy()
    {
        cout << "Enemy destroyed!" << endl;
    }

    int health = 100;
};

int main()
{
    unique_ptr<Enemy> enemy = make_unique<Enemy>(); // dynamically allocated memory for an Enemy object

    // Do something with enemy...
    cout << "Enemy health: " << enemy->health << endl;

    return 0;
}