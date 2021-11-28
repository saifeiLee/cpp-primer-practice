#include <iostream>
#include <vector>

using namespace std;

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