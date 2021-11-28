#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <set>

using namespace std;
class Folder;
class Message
{
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);

public:
    explicit Message(const std::string &str = "") : contents(str) {}
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();

    void save(Folder &);
    void remove(Folder &);

    void addFolders(Folder *);
    void removeFolders(Folder *);
    void reserve(size_t);

private:
    string contents;
    set<Folder *> folders;

    void add_to_Folders(const Message &);
    void remove_from_Folders();
};

void Message::reserve(size_t sz)
{
    contents.reserve(sz);
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

Message::~Message()
{
    remove_from_Folders();
}

Message &Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void Message::addFolders(Folder *f)
{
    folders.insert(f);
}
void Message::removeFolders(Folder *f)
{
    folders.erase(f);
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);

    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

class Folder
{
private:
    set<Message *> messages;

public:
    Folder() = default;
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();

    void addMsg(Message *);
    void remMsg(Message *);
};

Folder::~Folder()
{
    for (auto m : messages)
        m->remove(*this);
}

Folder::Folder(const Folder &f) : messages(f.messages)
{
    for (auto m : messages)
        m->save(*this);
}
