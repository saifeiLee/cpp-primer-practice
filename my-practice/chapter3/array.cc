#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string sa[10];
int ia[10];
int main()
{
    // string sa2[10];
    // int ia2[10];

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << ia2[i] << endl;
    // }
    // int ia[] = {0, 1, 2};
    // auto ia2(ia);

    // int *beg = std::begin(ia);
    // int *last = std::end(ia);

    // cout <<  *beg << endl;
    // int k = ia[-2];
    // cout << "k: " << k << endl;

    const char ca[] = {'h', 'h'};
    const char *cp = ca;
    while (*cp)
    {
        /* code */
        cout << *cp << endl;
        cp++;
    }
    
    return 0;
}