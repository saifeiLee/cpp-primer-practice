#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

int main()
{
    int tenInts[10];
    int *currentElement = begin(tenInts);
    int *lastElement = end(tenInts);

    while (currentElement != lastElement)
    {
        /* code */
        *currentElement = 0;
        ++currentElement;
    }
    for (auto element: tenInts) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}