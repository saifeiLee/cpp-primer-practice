#include <memory>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    shared_ptr<int> sp1 = make_shared<int>(1);
    shared_ptr<int> sp2(sp1);
    weak_ptr<int> wp(sp1);
    cout << wp.use_count() << endl;


    return 0;
}