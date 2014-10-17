#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string expandString(string s){
        int n = s.length();
        if (n==0) return "";
        string ret = "";
        for (int i = 0; i < n; i++)
            ret += "#" + s.substr(i, 1);
        ret += "#";

        return ret;
    }
    string longestPalindrome(string s) {
        string xs = expandString(s);
        int n = xs.length();
        int *P = new int[n];
        int C = 0, R = 0;
        for (int i = 0; i < n ; i++){
            int mirror_i = 2 * C - i;
            P[i] = (R > i) ? min(R-i, P[mirror_i]) : 0;

            while (xs[i + P[i] + 1] == xs[i - P[i] - 1]){
                P[i]++;
            }

            if (P[i] + i > R){
                R = P[i] + i;
                C = i;
            }
        }

        int maxLen = 0;
        for (int i = 0; i < n; i++){
            // cout << "(" << i << "," << P[i] << "," << xs[i] <<")\n";
            if (P[i] > maxLen){
                maxLen = P[i];
                C = i;
            }
        }
        return s.substr((C - maxLen)/2, maxLen);
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.longestPalindrome("babcbabcbaccba") << endl;
    return 0;
}