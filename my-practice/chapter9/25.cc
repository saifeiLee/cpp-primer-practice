
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"

using namespace std;

int main()
{
    list<int> vi = {1, 2, 2, 3, 4};
    auto it = vi.begin();
    while (it != vi.end())
    {
        if (*it % 2 != 0) {
            vi.erase(it);
        }
        it++;
    }
    for (auto &i: vi) {
        cout << i << endl;
    }
    return 0;
}