#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
int main()
{
    int i = 6;
    vector<int> ivec = {1, 2, 3};
    auto modulus_to_i = bind(modulus<int>(), i, placeholders::_1);
    auto result = find_if(ivec.cbegin(), ivec.cend(), modulus_to_i);
    if (result == ivec.cend())
        cout << "OK" << endl;
    else
        cout << "NO" << endl;
}