#include <string>
#include <iostream>

using namespace std;

class Window_mgr;

template <int H, int W>
class Screen;

template <int H, int W>
ostream &operator<<(ostream &os, const Screen<H, W> &s);

template <int H, int W>
class Screen
{
    friend ostream &operator<<<H, W>(ostream &os, const Screen<H, W> &s);

public:
    Screen() : contents(W * H, ' ') {}
    Screen(char c) : contents(H * W, c) {}
    friend class Window_mgr;
    char get() const { return contents[cursor]; }
    inline char get(int, int) const;
    Screen &clear(char = bkground);

    Screen &move(int r, int c);
    Screen &set(char);
    Screen &set(int, int, char);
    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(ostream &os) const
    {
        do_display(os);
        return *this;
    }

private:
    void do_display(ostream &os) const
    {
        os << contents;
    }
    int cursor = 0;
    string contents;
    static const char bkground = ' ';
};

template <int H, int W>
Screen<H, W> &Screen<H, W>::clear(char c)
{
    contents = string(H * W, c);
    return *this;
}

template <int H, int W>
inline Screen<H, W> &Screen<H, W>::move(int r, int c)
{
    cursor = r * W + c;
    return *this;
}

template <int H, int W>
char Screen<H, W>::get(int r, int c) const
{
    return contents[r * W + c];
}

template <int H, int W>
inline Screen<H, W> &Screen<H, W>::set(char c)
{
    contents[cursor] = c;
    return *this;
}

template <int H, int W>
inline Screen<H, W> &Screen<H, W>::set(int r, int c, char ch)
{
    contents[r * W + c] = ch;
    return *this;
}

template <int H, int W>
ostream &operator<<(ostream &os, const Screen<H, W> &s)
{
    os << s.contents;
    return os;
}

int main()
{
    Screen<5, 5> scr;
    scr.move(4, 0).set('X').display(cout);
    cout << endl;
    cout << scr << endl;
    return 0;
}
