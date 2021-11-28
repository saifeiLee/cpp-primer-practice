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
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];

    size_t cnt = 0;
    for (auto &row : ia)
    {
        for (auto &col : row)
        {
            col = cnt;
            ++cnt;
        }
    }

    for (auto &row : ia)
    {

        for (auto &col : row)
            cout << col << " ";
        cout << endl;
    }

    for (auto p = ia; p != ia + rowCnt; p++) {
        for (auto q = *p; q != *p + colCnt; q++) {
            cout << *q << ' ';
        }
        cout << endl;
    }

    for (auto p = begin(ia); p != end(ia); p++) {
        for (auto q = begin(*p); q != end(*p); q++) {
            cout << *q << " ";
        }
        cout <<endl;
    }
    return 0;
}