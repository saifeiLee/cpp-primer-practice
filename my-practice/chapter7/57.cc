class Account
{
public:
    void calculate() {}
    static double rate() { return interestRate; }
    static void rate(double);

private:
    static double interestRate;
    static double initRate();
}