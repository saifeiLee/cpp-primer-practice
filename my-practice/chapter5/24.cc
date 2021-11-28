#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int X;
    int Y;
    if (cin >> X >> Y)
    {
        /* code */
        cout << X << "/" << Y << " = " << X / Y << endl;
        if (Y == 0) {
            throw std::runtime_error("被除数不能是0");
        }
    }
    else
    {
        cerr << endl << "要两个整数" << endl;
        return -1;
    }
    return 0;
}