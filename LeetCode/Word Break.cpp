#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int l = s.length();

        vector<bool> opt(l+1, false);
        opt[0] = true;
        for (int i = 1; i <= l; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                string tmp = s.substr(j, i-j);
                if (opt[j] && dict.find(tmp) != dict.end())
                    opt[i] = true;
            }
        }
        return opt[l];
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    unordered_set<string> dict;
    dict.insert("aaaa");
    dict.insert("aa");
    string str("aaaaaaa");
    cout << s.wordBreak(str, dict) << endl;
    return 0;
}