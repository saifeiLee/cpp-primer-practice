#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5};
    auto beg = numbers.begin(), end = numbers.end();
    auto mid = numbers.begin() + (end - beg) / 2;
    int sought = 0;
    while (mid != end && *mid != sought)
    {
        /* code */
        if (sought < *mid) {
            end = mid;
        } else {
            beg = mid + 1;
        }
        mid = beg + (end - beg) / 2;
    }
    if (mid == end) {
        cout << "not found" << endl;
    } else {
        cout << "Found!" << endl;
    }
    return 0;
}