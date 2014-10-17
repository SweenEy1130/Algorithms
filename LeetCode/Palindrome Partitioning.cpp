#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        int l = s.length();
        vector<vector<string> > ans;
        vector<string> result;
        if (l==0){
            return ans;
        }
        dfs(s, 0, 1, result, &ans);
        return ans;
    }

    void dfs(string s, int start, int idx, vector<string> result, vector<vector<string> > * ans){
        if (idx == s.length()){
            if (isPalindrome(s, start+1, idx)){
                result.push_back(s.substr(start, idx-start));
                ans->push_back(result);
                return;
            }else{
                return;
            }
        }
        dfs(s,start, idx+1, result, ans);
        if (isPalindrome(s,start+1, idx)){
            result.push_back(s.substr(start, idx-start));
            start = idx;
            dfs(s, start, idx+1, result, ans);
        }
        return;
    }

    bool isPalindrome(string s, int sta, int end){
        while (sta <= end){
            if (s[sta-1] != s[end-1]){
                return false;
            }
            sta++;
            end--;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<string> > ans;
    ans = s.partition("aaaa");
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j< ans[i].size(); j++)
            cout << ans[i][j] << "\t";
        cout << endl;
    }
    return 0;
}