#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    // Declare second integer, double, and String variables.
    int a = 0;
    double b = 0.0;
    string str = "";
    // Read and save an integer, double, and String to your variables.
    cin >> a;
    cin.ignore();
    cin >> b;
    cin.ignore();
    getline(cin, str);
    // Print the sum of both integer variables on a new line.
    cout << i + a << endl;
    cout << fixed << setprecision(1);
    cout << d + b << endl;
    cout << s;
    cout << str << endl;

    // Print the sum of the double variables on a new line.

    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.

    return 0;
}