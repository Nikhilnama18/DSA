#include <iostream>
#include <vector>
using namespace std;

void allSubStrings(string &s, string cur, int pos)
{
    int n = s.size();
    if (pos >= n)
        return;

    allSubStrings(s, cur, pos + 1);
    cur = cur + s[pos];
    allSubStrings(s, cur, pos + 1);
    cout << cur << endl;
}

int main()
{
    string s = "abc";

    // cout << s << endl;
    allSubStrings(s, "", 0);

    return 0;
}
