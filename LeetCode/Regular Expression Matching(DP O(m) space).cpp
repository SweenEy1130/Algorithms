#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';  //empty
        int m = strlen(p), n = strlen(s);
        bool * OPT = new bool[m+1];
        bool * PRE = new bool[m+1];
        OPT[0] = PRE[0] = true;
        for (int j = 1; j <= m; ++j)
            OPT[j] = PRE[j] = (j >= 2 && p[j-1] == '*') && PRE[j-2];

        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                OPT[0] = false;
                OPT[j] = ((p[j-1] == s[i-1] || p[j-1] == '.') && PRE[j-1]) ||
                            ((p[j-1] == '*' && (p[j-2] == s[i-1] || p[j-2] == '.')) && PRE[j]) ||
                            (j-2 >= 0 && p[j-1] == '*' && OPT[j-2]);
            }
            for (int j = 0; j <= m; ++j)
                PRE[j] = OPT[j];
        }
        return OPT[m];
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.isMatch("aa", "a") << endl;
    cout << s.isMatch("a", "ab*") << endl;
    cout << s.isMatch("aa", "a*aab*") << endl;
    cout << s.isMatch("a", ".*..a*") << endl;
    cout << s.isMatch("", ".*") << endl;
    return 0;
}