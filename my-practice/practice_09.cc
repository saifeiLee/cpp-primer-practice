// Write a program that uses a while to sum the numbers
// from 50 to 100
#include <iostream>

int main()
{
    int i = 50;
    int limit = 100;
    int sum = 0;
    while (i < limit)
    {
        sum += i;
        i++;
    }
    std::cout << sum << std::endl;
}