#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
    int n, q, i;
    cin >> n >> q;
    cin.ignore();
    vector<string> hrml;
    string s;
    while (n-- > 0)
    {
        getline(cin, s);
        hrml.push_back(s);
    }
    vector<string> query;
    while (q-- > 0)
    {
        getline(cin, s);
        query.push_back(s);
    }
    map<string, string> m;
    char ch;
    string tag, property, value;
    vector<string> tag_stack;
    for (auto &i : hrml)
    {
        stringstream ss;
        ss.str("");
        i.erase(remove(i.begin(), i.end(), '\"'), i.end());
        i.erase(remove(i.begin(), i.end(), '>'), i.end());
        ss << i;
        if (i.substr(0, 2) == "</")
        {
            tag_stack.pop_back();
        }
        else
        {
            ss >> ch >> tag >> property >> ch >> value;
            string key = "";
            // 构造key,形式为: tag.tag.tag...tag.property
            if (tag_stack.size() > 0)
            {
                key = *tag_stack.rbegin() + "." + tag;
            }
            else
            {
                key = tag;
            }
            tag_stack.push_back(key);
            m[key + "~" + property] = value;
            while (ss)
            {
                ss >> property >> ch >> value;
                m[key + "~" + property] = value;
            }
        }
    }

    for (auto &q : query)
    {
        if (m.find(q) == m.end())
        {
            cout << "Not found!" << endl;
        }
        else
        {
            cout << m[q] << endl;
        }
    }
    return 0;
}