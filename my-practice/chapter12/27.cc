#include <memory>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../include/StrBlob.hpp"
#include <set>
#include <map>

using namespace std;
void runQueries(ifstream &);
class QueryResult;
class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &);
    QueryResult query(const string &) const;

private:
    shared_ptr<vector<string>> lines_;
    map<string, shared_ptr<set<line_no>>> wm_;
};

TextQuery::TextQuery(ifstream &infile) : lines_(make_shared<vector<string>>())
{
    string text;
    while (getline(infile, text))
    {
        lines_->push_back(text);
        istringstream line(text);
        string word;
        while (line >> word)
        {
            auto &lines = wm_[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(lines_->size() - 1);
        }
    }
}

class QueryResult
{
public:
    using line_no = vector<string>::size_type;
    friend ostream &print(ostream &, const QueryResult &);
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) : sought(s), lines(p), file(f){};

private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

QueryResult TextQuery::query(const string &sought) const
{

    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm_.find(sought);
    if (loc == wm_.end())
        return QueryResult(sought, nodata, lines_);
    else
        return QueryResult(sought, loc->second, lines_);
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

ostream &print(ostream &os, const QueryResult &qr)
{
    // cout << "test: " << qr.sought << endl;
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto num : *qr.lines)
    {
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    }
    return os;
}

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s));
    }
}

int main()
{
    ifstream infile("./test.js");
    runQueries(infile);
    return 0;
}