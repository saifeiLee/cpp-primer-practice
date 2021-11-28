
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"

using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    auto bg = begin(ia);
    auto ed = end(ia);
    vector<int> vi;
    list<int> li;
    while (bg != ed)
    {
        /* code */
        vi.push_back(*bg);
        li.push_back(*bg);
        ++bg;
    }

    auto it_vi = vi.begin();
    while (it_vi != vi.end())
    {
        /* code */
        if (*it_vi % 2 != 0)
        {
            it_vi = vi.erase(it_vi);  // erase返回被删除元素后的引用
        }
        else
        {
            ++it_vi;
        }
    }
    auto it_li = li.begin();
    while (it_li != li.end())
    {
        /* code */
        // 同上
    }
    
    return 0;
}