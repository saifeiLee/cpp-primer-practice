#ifndef SP_HPP
#define SP_HPP

#include <iostream>

template <typename T>
class SP
{
public:
    SP() : p(nullptr), use(nullptr) {}
    explicit SP(T *pt) : p(pt), use(new size_t(1)) {}
    

private:
    T *p;
    size_t *use;
};

#endif // SP_HPP