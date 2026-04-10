#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> scores = {100, 90, 80};

    scores.push_back(70); // add a new score to the end of the vector
    scores.push_back(60);

    cout << "Score knows it's size: " << scores.size() << endl;

    cout << "first score: " << scores[0] << endl;

    cout << "All scores: ";

    for (int i = 0; i < scores.size(); i++)
    {
        cout << scores[i] << " ";
    }
    cout << endl;
    cout << "All scores using range-based for loop: ";
    for (const int &score : scores)
    {
        cout << score << " ";
    }
    cout << endl;

    return 0;
}