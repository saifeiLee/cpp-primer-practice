#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "../include/print_vec.hpp"

using namespace std;
int main(int argc, char *argv[])
{
    vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> vi2;
    vector<int> vi3;
    vector<int> vi4;

    auto bg = vi.begin();
    auto ed = vi.end();
    copy(bg, ed, inserter(vi4, vi4.begin()));
    copy(bg, ed, front_inserter(vi2));
    copy(bg, ed, back_inserter(vi3));

    print_vector(vi4);
    print_list(vi2);
    print_vector(vi3);
    return 0;
}