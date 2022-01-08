#include <iostream>

using namespace std;

class BadLengthException
{
public:
    BadLengthException(int n)
    {
        this->n = n;
    }
    int what()
    {
        return this->n;
    }

private:
    int n;
};

int main()
{
}