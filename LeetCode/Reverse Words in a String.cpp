#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
        string ans;
        int pos = 0;
        s = s + ' ';
        for (int i = 0; i <= s.length(); i++)
        {
            if (s[i] == ' '){
                ans = (ans=="")?s.substr(pos,i-pos):(s.substr(pos, i-pos) + " " + ans);
                while (s[i] == ' '){
                    i++;
                    pos = i;
                }
            }
        }
        s = ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    // string s("a");
    string s("  the sky is   blue  ");
    cout << s << endl;
    sol.reverseWords(s);
    cout << s << endl;
    return 0;
}