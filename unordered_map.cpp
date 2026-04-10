#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> scores;

    scores["Aadarsh"] = 100;
    scores["Satpal"] = 99;
    scores["Raj"] = 45;

    cout << "size of map: " << scores.size() << endl;

    // In js, if you try to access a key that doesn't exist, it will return undefined. In c++, It will create a new key with a default value (0 for int, empty string for string, etc.) and return that value. see below example.
    cout << "trying to access a key that doesn't exist: " << scores["John"] << endl;            // this will create a new key "John" with value 0 and return 0
    cout << "size of map after trying to access a non-existent key: " << scores.size() << endl; // size will be 4 now because we added a new key "John"

    // safe lookup using find() method

    if (scores.find("Jiga") != scores.end())
    {
        cout << "Jiga's score: " << scores["Jiga"] << endl;
    }
    else
    {
        cout << "Jiga's score not found" << endl;
    }

    for (const auto &pair : scores)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}