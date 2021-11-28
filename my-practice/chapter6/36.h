#include <string>
#include <vector>
using namespace std;

string (&example())[10];

using stringArray = string[10];
stringArray &myFun();

auto myFun2() -> string (&)[10];

string arrayT[10];
decltype(arrayT) &myFun3();