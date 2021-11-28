#include <memory>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    unique_ptr<int> p(new int(1));
    unique_ptr<int> q(p);
    return 0;
}