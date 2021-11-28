#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> ivec;

    cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;

    for (vector<int>::size_type ix = 0; ix != 24; ++ix)
    {
        ivec.push_back(ix);
    }

    ivec.reserve(50);
    cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
    
    while (ivec.size() != ivec.capacity())
    {
        /* code */
        ivec.push_back(0);
    }

    ivec.push_back(1);
    
    cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
    return 0;
}