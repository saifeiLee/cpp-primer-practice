#include <vector>
#include <list>
#include <forward_list>
#include <string>

using namespace std;
int main()
{
    list<string> authors = {"A", "B", "C"};
    vector<const char *> articles = {"a", "b", "c"};
    // vector<string> words(articles);
    forward_list<string> words(articles.begin(), articles.end());
    // string name = "123";
    // const char* test = name;
}