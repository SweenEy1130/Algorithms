/*
Time complexity is good at O(mn), however it exceeds the memory limit for the largest data set.
*/
#include <iostream>
using namespace std;
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int ls = 0, lp = 0;
        const char *t = s;
        while (*t != '\0') {t++;ls++;}
        t = p;
        while (*t != '\0') {t++;lp++;}

        bool **opt = new bool*[ls+1];
        for (int i = 0; i <= ls; ++i)
        {
            opt[i] = new bool[lp+1];
            opt[i][0] = false;
        }
        opt[0][0] = true;
        for (int i = 1; i <= lp; ++i)
            opt[0][i] = (p[i-1] == '*') && opt[0][i-1];

        for (int i = 1; i <= ls; ++i)
            for (int j = 1; j <= lp; ++j){
                opt[i][j] = ((s[i-1] == p[j-1] || p[j-1] == '.') && opt[i-1][j-1]) ||
                            (p[j-1] == '*' && (opt[i-1][j] || opt[i][j-1]));
            }
        return opt[ls][lp];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.isMatch("aab", ".*a*b") << endl;
    return 0;
}