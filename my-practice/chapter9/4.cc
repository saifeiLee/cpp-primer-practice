#include <vector>

using namespace std;

bool find_i(vector<int>::iterator begin, vector<int>::iterator end, int value)
{
    while (begin != end && begin < end)
    {
        if (*begin == value)
            return true;
        else
            ++begin;
    }
    return false;
}