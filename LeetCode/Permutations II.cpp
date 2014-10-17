#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<vector<int> > ans;
    int size;
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        size = num.size();
        if (size == 0) return ans;
        vector<int> digits;
        vector<int> counts;
        sort(num.begin(), num.end());

        digits.push_back(num[0]);
        counts.push_back(1);
        int idx = 0;
        for (int i = 1; i < num.size(); ++i)
        {
            if (num[i] != num[i-1]){
                idx++;
                digits.push_back(num[i]);
                counts.push_back(1);
            }else{
                counts[idx]++;
            }
        }

        vector<int> res;
        generatePermute(digits, counts, res, 0);

        return ans;
    }

    void generatePermute(const vector<int> digits, vector<int> counts, vector<int> res, int step){
        if (step == size){
            ans.push_back(res);
            return;
        }

        for (int i = 0; i < digits.size(); ++i)
        {
            if (counts[i] > 0){
                counts[i]--;
                res.push_back(digits[i]);
                generatePermute(digits, counts, res, step+1);
                res.pop_back();
                counts[i]++;
            }
        }
        return;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    sol.permuteUnique(num);
    return 0;
}