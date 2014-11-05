#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		int l = s.length();
		vector<bool> opt(l+1, false);
		vector<vector<string> > res(l+1, vector<string>(0));
		res[0].push_back("");

		opt[0] = true;
		for (int i = 1; i <= l; ++i)
			for (int j = 0; j < i; ++j){
				string tmp = s.substr(j, i-j);
				if (opt[j] && dict.find(tmp) != dict.end()){
					opt[i] = true;
					for (int k = 0; k < res[j].size(); ++k)
						res[i].push_back(res[j][k] + " " + tmp);
				}
			}
		return res[l];
	}
};

int main(int argc, char const *argv[])
{
    Solution s;
    unordered_set<string> dict;
    dict.insert("aaaa");
    dict.insert("aa");
    string str("aaaaaa");
    vector<string> ans = s.wordBreak(str, dict);
    for (int i = 0; i < ans.size(); ++i)
    {
    	cout << ans[i] << endl;
    }
    return 0;
}
