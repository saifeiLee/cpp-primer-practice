#include <iostream>
#include <vector>
#include <list>

using namespace std;


bool is_equal_iv_il(vector<int> iv, list<int> il) {
    vector<int> iv_2(il.begin(), il.end());
    return iv == iv_2;
}

int main()
{
    vector<int> vInt1 = {1, 2};
    vector<int> vInt2 = {1, 2};
    if (vInt1 == vInt2) {
        cout << "=" << endl;
    } else {
        cout <<"!=" << endl;
    }

    return 0;
}