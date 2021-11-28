struct LongDouble
{
    LongDouble(double = 0.0);
    operator double() const;
    operator float() const;
};
int main()
{
    LongDouble ldObj;
    // int ex1 = ldObj;
}