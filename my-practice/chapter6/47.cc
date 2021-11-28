#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int>::iterator biter, vector<int>::iterator eiter) {
    if (biter != eiter)
    {
        /* code */
        #ifndef NDEBUG
        cerr << "The size of vector: " << eiter - biter << endl;
        #endif

        cout << *biter << endl;
        print_vector(++biter, eiter);
    }
    
}

int main() {
    vector<int> list = {1, 2, 3};
    int a = 0;
    assert(a == 0);
    cout << "assert ???" << endl;
    // print_vector(list.begin(), list.end());
    return 0;
}