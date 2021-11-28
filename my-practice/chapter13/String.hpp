#ifndef STRING_HPP
#define STRING_HPP
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>
using namespace std;
class String
{
    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend ostream &operator<<(ostream &, const String &);

public:
    String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const char *);
    String(const String &);
    String(String &&) noexcept;
    String &operator=(const String &);
    String &operator=(String &&) noexcept;
    char &operator[](size_t n);
    const char &operator[](size_t n) const;
    ~String();
    void push_back(const char &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char *begin() const { return elements; }
    char *end() const { return first_free; }
    ostream &print();

private:
    allocator<char> alloc; /* it using static, 'undefined reference' reported when compile */
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    pair<char *, char *> alloc_n_copy(const char *, const char *);
    void free();
    void reallocate(size_t n = 0);
    char *elements;
    char *first_free;
    char *cap;
};

String::String(const char *s)
{
    auto newdata = alloc_n_copy(s, s + strlen(s));
    elements = newdata.first;
    first_free = cap = newdata.second;
}

String::String(const String &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

String::String(String &&s) noexcept
{
    cout << "移动构造" << endl;
    elements = s.elements;
    first_free = s.first_free;
    cap = s.cap;
    s.elements = s.first_free = s.cap = nullptr;
}

String &String::operator=(const String &rhs)
{
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

String &String::operator=(String &&rhs) noexcept
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

String::~String()
{
    free();
}

void String::free()
{
    if (elements)
        alloc.deallocate(elements, cap - elements);
}

void String::reallocate(size_t n)
{
    auto newcapacity = size() + n;
    if (n == 0)
        newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void String::push_back(const char &c)
{
    chk_n_alloc();
    alloc.construct(first_free++, c);
}

ostream &String::print()
{
    for (auto p = elements; p != first_free; ++p)
        cout << *p;
    return cout;
}

pair<char *, char *> String::alloc_n_copy(const char *b, const char *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

ostream &operator<<(ostream &os, const String &s)
{
    for (auto p = s.begin(); p != s.end(); ++p)
        os << *p;
    return os;
}

#endif // STRING_HPP