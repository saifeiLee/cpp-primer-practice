#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);

public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr &hp)
    {
        ps = new string(*hp.ps);
        i = hp.i;
        use = hp.use;
        ++*use;
    }
    HasPtr &operator=(const HasPtr &hp)
    {
        ++*hp.use;
        if (--*use == 0)
        {
            delete ps;
            delete use;
        }
        ps = hp.ps;
        i = hp.i;
        use = hp.use;
        return *this;
    }
    // 注意是值传递,将会调用拷贝构造函数
    HasPtr &operator=(HasPtr rhs)
    {
        swap(*this, rhs);
        return *this;
    }
    ~HasPtr()
    {
        if (--*use == 0)
        {
            delete ps;
            delete use;
        }
    }

private:
    string *ps;
    int i;
    size_t *use;
};

void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.i, rhs.i);
    swap(lhs.ps, rhs.ps);
    swap(lhs.use, rhs.use);
}

int main()
{
    int i = 12;
    int *pi = &i;
    delete pi;
    return 0;
}