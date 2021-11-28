#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <string>
class Screen
{
public:
    // typedef std::string::size_type pos;
    using pos = std::string::size_type;

    Screen() = default;

    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    char get() const
    {
        return contents[cursor];
    }

    char get(pos ht, pos wd) const;

    Screen &set(char c);

    Screen &set(pos r, pos col, char c);

    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    void do_display(std::ostream &os) const { os << contents; }
};

inline char Screen::get(pos ht, pos wd) const
{
    return contents[(ht * width) + wd];
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}

#endif