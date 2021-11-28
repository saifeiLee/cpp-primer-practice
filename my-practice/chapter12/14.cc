#include <memory>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct destination;
struct connection;
connection connect(destination *);
void disconnect(connection);
void f(destination &d)
{
}

void end_connection(connection *p)
{
    disconnect(*p);
}
int main()
{
    return 0;
}