#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';  //empty
        const char * tmp = s;
        int m = 0, n = 0;
        while (*tmp != '\0'){n++;tmp++;}
        tmp = p;
        while (*tmp != '\0'){m++;tmp++;}

        bool ** OPT = new bool*[n+1];
        for (int i = 0; i <= n; ++i){
            OPT[i] = new bool[m+1];
            OPT[i][0] = false;
        }
        OPT[0][0] = true;
        for (int j = 1; j <= m; ++j)
            OPT[0][j] = (j >= 2 && p[j-1] == '*') && OPT[0][j-2];

        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                OPT[i][j] = ((p[j-1] == s[i-1] || p[j-1] == '.') && OPT[i-1][j-1]) ||
                            ((p[j-1] == '*' && (p[j-2] == s[i-1] || p[j-2] == '.')) && OPT[i-1][j]) ||
                            (j-2 >= 0 && p[j-1] == '*' && OPT[i][j-2]);
            }
        }
        return OPT[n][m];
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // cout << s.isMatch("a", "ab*") << endl;
    // cout << s.isMatch("aa", "a*aab*") << endl;
    cout << s.isMatch("a", ".*..a*") << endl;
    return 0;
}