#include <iostream>

int main()
{
    int v1 = 0;
    int v2 = 0;
    std::cout << "Enter 2 numbers:";
    std::cin >> v1;
    std::cin >> v2;
    std::cout
        << "The sum is of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 + v2 << std::endl;
    return 0;
}