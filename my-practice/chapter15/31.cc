#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <sstream>

using namespace std;

class QueryResult;

class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &);
    QueryResult query(const string &) const;

private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<int>>> wm;
};

TextQuery::TextQuery(ifstream &is)
{
    string line;
    while (getline(is, line))
    {
        file->push_back(line);
        int n = file->size() - 1; // line number
        istringstream iss(line);
        string word;
        while (iss >> word)
        {
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<int>); // first time query this word
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<int>> nodata(new set<int>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

class QueryResult
{
public:
    QueryResult(string s, shared_ptr<set<int>> p, shared_ptr<vector<string>> f)
        : sought(s), lines(p), file(f) {}
    string sought;
    shared_ptr<set<int>> lines;
    shared_ptr<vector<string>> file;
};

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << (*qr.file)[num] << endl;
}
void runQueries(ifstream &infile)
{
    string line;
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
}