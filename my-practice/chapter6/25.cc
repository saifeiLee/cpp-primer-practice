#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    if (argc == 3) {
        cout << argv[1] << " " << argv[2] << endl;
        return 0;
    }    
}