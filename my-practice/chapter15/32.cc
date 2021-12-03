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

// ----------分割线----------//

class Query;
class Query_base
{
    friend class Query;

protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

public:
    Query(const std::string &);
    QueryResult eval(const TextQuery &t) const
    {
        return q->eval(t);
    }
    string rep() const
    {
        return q->rep();
    }

private:
    Query(std::shared_ptr<Query_base> query) : q(query) {}
    shared_ptr<Query_base> q;
};

class WordQuery : public Query_base
{
    friend class Query;
    WordQuery(const string &s) : query_word(s) {}

    QueryResult eval(const TextQuery &t) const { return t.query(query_word); }

    string rep() const { return query_word; }
    string query_word;
};

inline Query::Query(const string &s) : q(new WordQuery(s)) {}

class NotQuery : public Query_base
{
    friend Query operator~(const Query &);

    NotQuery(const Query &q) : query(q) {}
    string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery &) const;
    Query query;
};

inline Query operator~(const Query &operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base
{
protected:
    BinaryQuery(const Query &l, const Query &r, string s) : lhs(l), rhs(r), opSym(s) {}

    string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }

    Query lhs, rhs;

    string opSym;
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {}
    QueryResult eval(const TextQuery &) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") {}
    QueryResult eval(const TextQuery &) const;
};

Query operator|(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery& text) const {
    auto right = rhs.eval(text), left = lhs.eval(text);
    // auto ret_lines = make_shared<set<line_no>>(left.begin)
}