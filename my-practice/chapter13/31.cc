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

    bool operator<(const HasPtr &rhs) const
    {
        return *ps < *rhs.ps;
    }

private:
    string *ps;
    int i;
    size_t *use;
};

void swap(HasPtr &lhs, HasPtr &rhs)
{   
    cout << "swap " << *lhs.ps << " " << *rhs.ps << endl;
    using std::swap;
    swap(lhs.i, rhs.i);
    swap(lhs.ps, rhs.ps);
    swap(lhs.use, rhs.use);
}

int main()
{
    vector<HasPtr> vhp;
    vhp.push_back(HasPtr("hello"));
    vhp.push_back(HasPtr("world"));
    vhp.push_back(HasPtr("test"));
    sort(vhp.begin(), vhp.end());
    return 0;
}