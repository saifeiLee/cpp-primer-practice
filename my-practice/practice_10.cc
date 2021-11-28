// Write your own version of a program that prints the sum of a set of
// integers read from cin.

#include <iostream>

int main() {
    int sum = 0;
    std::cout << "Input number" << std::endl;
    int num = 0;
    while (std::cin >> num)
    {
        sum += num;
    }
    std::cout << "Sum is " << sum << std::endl;
    return 0;
}