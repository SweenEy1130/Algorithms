#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> IntMap;
        vector<int> ret;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (IntMap.find(target-numbers[i]) != IntMap.end()){
                ret.push_back(IntMap[target-numbers[i]]+1);
                ret.push_back(i+1);
                return ret;
            }
            IntMap[numbers[i]] = i;
        }
        return ret;
    }
};