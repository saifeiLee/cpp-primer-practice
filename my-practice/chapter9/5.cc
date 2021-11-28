#include <vector>
#include <list>
using namespace std;

using vit = vector<int>::iterator;

// 利用了end迭代器是开区间的特点，可以用来标记没找到
vit find_i(vector<int>::iterator begin, vector<int>::iterator end, int value)
{
    while (begin != end && begin < end)
    {
        if (*begin == value)
            return begin;
        else
            ++begin;
    }
    return end;
}