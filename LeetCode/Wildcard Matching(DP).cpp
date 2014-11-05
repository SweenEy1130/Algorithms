/*
Time complexity is good at O(mn), however it exceeds the memory limit for the largest data set.
*/
#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int ls = strlen(s), lp = strlen(p);

        bool * opt = new bool[lp+1];
        bool * pre = new bool[lp+1];
        pre[0] = opt[0] = true;
        for (int i = 1; i <= lp; ++i)
            opt[i] = pre[i] = (p[i-1] == '*') && pre[i-1];

        for (int i = 1; i <= ls; ++i){
            opt[0] = false;
            for (int j = 1; j <= lp; ++j){
                opt[j] = ((s[i-1] == p[j-1] || p[j-1] == '.') && pre[j-1]) ||
                            (p[j-1] == '*' && (pre[j] || opt[j-1]));
            }
            for (int j = 0; j <= lp; ++j)
                pre[j] = opt[j];
        }
        return opt[lp];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.isMatch("aab", ".*a*b") << endl;
    return 0;
}