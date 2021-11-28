#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../include/StrBlob.hpp"

using namespace std;
int main()
{
    const char hello[] = "hello";
    const char world[] = "world";
    size_t sz = strlen(hello) + strlen(world) + 1;
    char *p = new char[sz];
    strcpy(p, hello);
    strcat(p, " ");
    strcat(p, world);
    cout << p << endl;
    return 0;
}