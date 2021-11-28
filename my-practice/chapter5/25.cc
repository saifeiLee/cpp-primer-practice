
#include <iostream>
#include <stdexcept>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int X;
    int Y;
    while (cin >> X >> Y)
    {
        try
        {
            if (Y == 0)
            {
                throw std::logic_error("被除数是0了❎");
            }
            cout << "OK" << endl;
            return 0;
        }
        catch (const std::logic_error &e)
        {
            cout << e.what() << " Try again?[y/n]";
            char response;
            cin >> response;
            if (!cin || response == 'n') {
                break;
            }
            cout << "再输入X, Y" << endl;
        }
    }
    cout << endl << "Error, 要2个整数" << endl;
    return -1;
}