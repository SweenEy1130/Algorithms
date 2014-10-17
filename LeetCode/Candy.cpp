#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int len = ratings.size();
        int * left = new int[len], * right = new int[len];
        for (int i = 0; i < len; ++i){
            left[i] = 1;
            right[i] = 1;
        }
        for (int i = 1; i < len; ++i){
            left[i] = (ratings[i] > ratings[i-1])?(left[i-1]+1):left[i];
        }

        for (int i = len-1; i>=0; --i){
            right[i] = (ratings[i+1] < ratings[i])?(right[i+1]+1):right[i];
        }

        int sum = 0;
        for (int i = 0; i < len; ++i)
            sum += (left[i] > right[i])?left[i]:right[i];

        return sum;
    }
};

int main(int argc, char const *argv[])
{
    int rt[5] = {1,2,4,4,3};
    vector<int> ratings;
    for (int i = 0; i < 5; ++i)
    {
        ratings.push_back(rt[i]);
    }
    Solution s;
    cout << s.candy(ratings) << endl;
    return 0;
}