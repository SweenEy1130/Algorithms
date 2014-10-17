#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int ls = S.length();
        int ll = L.size();
        int lw = L[0].length();
        vector<int> ans;
        if (ls == 0 || ll == 0) return ans;

        map<string, int> wordTable;
        for (int i = 0; i < ll; ++i){
            if (wordTable.find(L[i]) == wordTable.end() ){
                wordTable[L[i]] = 1;
            }else
                wordTable[L[i]]++;
        }

        for (int i = 0; i < lw; i++){
            map<string, int> wordWindow;
            int start_idx = i, cnt = 0;
            for (int end_idx = i; end_idx <= ls - lw; end_idx += lw){
                string ts = S.substr(end_idx, lw);
                if (wordTable.find(ts) != wordTable.end()){
                    if (wordWindow.find(ts) == wordWindow.end()){
                        wordWindow[ts] = 1;
                    }else wordWindow[ts]++;

                    cnt++;
                    if (wordWindow[ts] > wordTable[ts]){
                        for (int k = start_idx; ; k += lw){
                            string tmp = S.substr(k, lw);
                            wordWindow[tmp]--;
                            cnt--;
                            if (ts == tmp){
                                start_idx = k + lw;
                                break;
                            }
                        }
                    }

                    if (cnt == ll){
                        ans.push_back(start_idx);
                    }
                }else{
                    start_idx = end_idx + lw;
                    wordWindow.clear();
                    cnt = 0;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> L;
    L.push_back("foo");
    L.push_back("bar");
    string S = "barfoothefoobarman";
    vector<int> ans = s.findSubstring(S, L);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
