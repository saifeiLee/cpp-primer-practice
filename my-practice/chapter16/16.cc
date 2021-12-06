#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

template <typename T>
class Vec
{
    friend ostream &operator<<(ostream &, const Vec &);

public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(const initializer_list<T> &);
    Vec(const Vec &);
    Vec &operator=(const Vec &);
    Vec &operator=(Vec &&) noexcept;
    Vec &operator=(initializer_list<T>);
    ~Vec();

    void push_back(const T &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    T *begin() const { return elements; }
    T *end() const { return first_free; }

private:
    static allocator<T> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }

    pair<T *, T *> alloc_n_copy(const T *, const T *);
    void free();
    void reallocate();
    T *elements;
    T *first_free;
    T *cap;
};
template <typename T>
allocator<T> Vec<T>::alloc;
template <typename T>
Vec<T>::Vec(const initializer_list<T> &il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
template <typename T>
void Vec<T>::push_back(const T &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

template <typename T>
pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}
template <typename T>
void Vec<T>::free()
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
template <typename T>
Vec<T>::Vec(const Vec &s)
{
    cout << "拷贝构造" << endl;
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
template <typename T>
Vec<T>::~Vec()
{
    free();
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs)
{
    cout << "拷贝赋值" << endl;
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
template <typename T>
Vec<T> &Vec<T>::operator=(initializer_list<T> il)
{
    cout << "列表初始化赋值" << endl;
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
void Vec<T>::reallocate()
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

template <typename T>
ostream &operator<<(ostream &os, const Vec<T> &s)
{
    for (auto p = s.begin(); p != s.end(); ++p)
        os << *p << " ";
    return os;
}
template <typename T>
Vec<T> &Vec<T>::operator=(Vec<T> &&rhs) noexcept
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

int main()
{
    Vec<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto s = v1.size();
    cout << s << endl;
    return 0;
}