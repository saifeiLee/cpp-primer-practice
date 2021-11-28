class NoDefault
{
    int im;

public:
    NoDefault(int i) : im(i) {}
};

class C
{
    NoDefault n_number;

public:
    C(int i) : n_number(NoDefault(i)) {}
    C() : C(0) {}
};