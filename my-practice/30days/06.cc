#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    string userInput = "";
    int N = 0;
    cin >> N;
    while (N-- > 0)
    {
        /* code */
        cin >> userInput;
        string firstStr = "";
        string secondStr = "";

        for (int i = 0; i < userInput.size(); ++i) {
            if (i % 2 == 0) {
                firstStr += userInput[i];
            } else {
                secondStr += userInput[i];
            }
        }
        cout << firstStr << " " << secondStr << endl;
    }
    
    return 0;
}
