#include <iostream>
#include <iterator>
#include <vector>

using std::begin;
using std::cerr;
using std::cout;
using std::end;
using std::endl;
using std::vector;

int main()
{
    const vector<int> intVector = {1, 2, 3, 4, 5};
    int intArray[5];
    const auto arraySize = end(intArray) - begin(intArray);

    if (intVector.end() - intVector.begin() == arraySize)
    {
        for (auto i = 0; i != arraySize; i++)
        {
            intArray[i] = intVector[i];
        }
    }
    else
    {
        cout << "Not match" << endl;
    }

    for (auto elm : intArray)
    {
        cout << elm << endl;
    }
    return 0;
}