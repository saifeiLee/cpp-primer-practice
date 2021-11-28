#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string temp;
    getline(cin, temp);
    int count = stoi(temp);
    string key = "";
    long value;
    map<string, long> phoneNum;
    while (count-- > 0)
    {
        cin >> key >> value;
        // phoneNum.insert(key, value);
        phoneNum[key] = value;
    }
    string name;
    cin.ignore();
    while (cin >> name)
    {
        /* code */
        if (phoneNum.find(name) != phoneNum.end())
        {
            cout << name << "=" << phoneNum.find(name)->second << endl;
        }
        else
        {
            cout << "Not found" << endl;
        }
    }

    return 0;
}
