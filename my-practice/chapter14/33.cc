#include <iostream>
using namespace std;

struct absInt {
    int operator()(int x) {
        return x < 0 ? -x : x;
    }
};
int main() {
    int i = -42;
    absInt abs;
    int ui = abs(i);
    cout << ui << endl;
    return 0;
}