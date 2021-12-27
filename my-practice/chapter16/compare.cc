#include <iostream>

using namespace std;

template <typename T, typename F = less<T>>
int compare(T const &a, T const &b, F f = F())
{
    if (f(a, b))
        return -1;
    else if (f(b, a))
        return 1;
    else
        return 0;
}

int main()
{
    cout << compare(1, 2) << endl;
    cout << compare(1, 2, greater<int>()) << endl;
    cout << compare(1, 2, less<int>()) << endl;
    cout << compare(1, 2, greater_equal<int>()) << endl;
    cout << compare(1, 2, less_equal<int>()) << endl;
    cout << compare(1, 2, equal_to<int>()) << endl;
    cout << compare(1, 2, not_equal_to<int>()) << endl;
    return 0;
}