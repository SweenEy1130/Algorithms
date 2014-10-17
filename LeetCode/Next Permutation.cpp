#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int k, t, l = num.size();
        if (l == 0) return;

        for (int i = l-1; i >= 0; --i)
            if (i == 0 || num[i] > num[i-1]){
                k = i-1;
                break;
            }

        if (k < 0){
            reverse(num, 0, l-1);
            return;
        }

        for (int i = k+1; i < l; ++i)
            if (num[i] > num[k]){
                t = i;
            }else{
                break;
            }

        swap(num[k], num[t]);
        reverse(num, k+1, l-1);
        return;
    }

    void reverse(vector<int> &num, int st, int end){
        while(st < end){
            swap(num[st], num[end]);
            st++;
            end--;
        }
        return;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> num;
    // int a[] = {6,8,7,4,3,2};
    int a[] = {3,2,1};
    for (int i = 0; i < 3; ++i)
        num.push_back(a[i]);
    s.nextPermutation(num);
    for (int i = 0; i < num.size(); ++i)
        cout << num[i] << " ";
    cout << endl;
    return 0;
}