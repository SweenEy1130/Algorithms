#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ana;
        if (strs.size() <=1) return ana;
        unordered_map<string, int> hashtable;

        for (int i = 0; i < strs.size(); ++i)
        {
            string t = strs[i];
            sort(t.begin(), t.end());
            if (hashtable.find(t) == hashtable.end()){
                hashtable.insert(make_pair(t, i));
            }else{
                if (hashtable[t] >= 0){
                    ana.push_back(strs[hashtable[t]]);
                    hashtable[t] = -1;
                }
                ana.push_back(strs[i]);
            }
        }
        return ana;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("and");
    strs.push_back("den");
    strs.push_back("ned");

    vector<string> ana = s.anagrams(strs);
    for (int i=0; i < ana.size(); i++)
        cout << ana[i] << " ";
    cout << endl;
    return 0;
}