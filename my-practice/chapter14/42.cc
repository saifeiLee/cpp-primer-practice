#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
int main()
{
    auto greater_than_42 = bind(greater<int>(), placeholders::_1, 42);
    auto not_equal_to_lsf = bind(not_equal_to<string>(), placeholders::_1, "lsf");
    auto multiply_by_2 = bind(multiplies<int>(), placeholders::_1, 2);
    bool greater_than_42_result = greater_than_42(42);
    bool not_equal_to_lsf_result = not_equal_to_lsf("lsf");
    int multiply_by_2_result = multiply_by_2(42);
    cout << greater_than_42_result << endl;
    cout << not_equal_to_lsf_result << endl;
    cout << multiply_by_2_result << endl;
    return 0;
}