#include <iostream>

class Entity
{
public:
    virtual void print() const
    {
        std::cout << "I am an Entity" << std::endl;
    }
};

class Player : public Entity
{
public:
    void print() const override
    {
        std::cout << "I am a Player" << std::endl;
    };
};

int main()
{
    Entity *entity = new Player(); // Late binding: the type of the object (Player) is determined at runtime, not at compile time.
    entity->print();               // Output: "I am a Player" because of late binding (dynamic dispatch)
}