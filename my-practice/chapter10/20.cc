#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
    vector<string> vs = {"123123123", "123", "1111111"};
    size_t count = count_if(vs.begin(), vs.end(), [](string &s){
        return s.size() > 6;
    });
    cout << count << " words longer than 6"<< endl;
    return 0;
}