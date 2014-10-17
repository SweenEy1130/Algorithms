#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        if (num.size() < 3) return ret;

        sort(num.begin(), num.end());

        for (int i = 0; i < num.size() - 2; ++i)
        {
            if (i != 0 && num[i] == num[i-1]) continue;
            int start = i + 1, end = num.size() - 1;
            int target = 0 - num[i];
            while (start < end){
                if (start != i+1 && num[start] == num[start-1]){
                    start++;
                    continue;
                }
                if (num[start] + num[end] > target){
                    end--;
                }else if (num[start] + num[end] < target){
                    start++;
                }else{
                    vector<int>  ans;
                    ans.push_back(num[i]);
                    ans.push_back(num[start]);
                    ans.push_back(num[end]);
                    ret.push_back(ans);
                    end--;
                    start++;
                }
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> num;
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    vector<vector<int> > ans = sol.threeSum(num);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0 ; j < ans[i].size(); j++){
            cout << ans[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}