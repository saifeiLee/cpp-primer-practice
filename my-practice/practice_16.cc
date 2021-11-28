// Write your own version of a program that prints the sum of a set of
// integers read from cin.

#include <iostream>

int main() {
    int number = 0;
    int sum = 0;
    while (std::cin >> number)
    {
        sum += number;
    }
    std::cout << sum << std::endl;
    return 0;
}