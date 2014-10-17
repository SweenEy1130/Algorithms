#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = (int)s.size();

        std::vector<bool> dp(n+1, false);
        dp[0]=true;
        for (int i = 1; i < n+1; i++){
            int index = i - 1;
            if (dp[index]){
                int j = index;
                for(;j<n+1;j++){
                    string sub = s.substr(index, j-index+1);
                    if (dict.count(sub) != 0){
                        dp[j+1] = true;
                    }
                }
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    unordered_set<string> dict;
    string str("a");
    cout << s.wordBreak(str, dict) << endl;
    return 0;
}