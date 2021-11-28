#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade)
    {
        if (grade <= 100) {
            *(scores.begin() + grade / 10) += 1;
        }
    }

    for (auto iter = scores.cbegin(); iter != scores.cend() - 1; ++iter) {
        cout << *iter << " ";
    }
    cout << *(scores.cend() - 1) << endl;
    
    return 0;
}