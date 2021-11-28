#ifndef STRVEC_HPP
#define STRVEC_HPP
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class StrVec
{
    friend ostream &operator<<(ostream &, const StrVec &);

public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const initializer_list<string> &);
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    StrVec &operator=(StrVec &&) noexcept;
    StrVec &operator=(initializer_list<string>);
    ~StrVec();

    void push_back(const string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }

private:
    static allocator<string> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }

    pair<string *, string *> alloc_n_copy(const string *, const string *);
    void free();
    void reallocate();
    string *elements;
    string *first_free;
    string *cap;
};
allocator<string> StrVec::alloc;
StrVec::StrVec(const initializer_list<string> &il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        size_t sz = cap - elements;
        cout << "sz = " << sz << endl;
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    cout << "拷贝构造" << endl;
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    cout << "拷贝赋值" << endl;
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec &StrVec::operator=(initializer_list<string> il)
{
    cout << "列表初始化赋值" << endl;
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elm = elements;
    for (size_t i = 0; i != size(); ++i)
    {
        // alloc.construct(dest++, std::move(*elm++));
        alloc.construct(dest++, *elm++);
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

ostream &operator<<(ostream &os, const StrVec &s)
{
    for (auto p = s.begin(); p != s.end(); ++p)
        os << *p << " ";
    return os;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    cout << "移动赋值" << endl;
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

#endif