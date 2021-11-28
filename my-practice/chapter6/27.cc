#include <iostream>
#include <initializer_list>

using std::cout;
using std::endl;
using std::initializer_list;

int get_sum(initializer_list<int> const& values) {
    int sum = 0;
    for (auto i: values) {
        sum += i;
    }
    return sum;
}

int main() {
    cout << get_sum({1, 2, 3}) << endl;
    return 0;
}