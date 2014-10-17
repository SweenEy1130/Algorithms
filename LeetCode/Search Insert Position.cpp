#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int m, l = 0, r = n-1;
        while (l <= r){
            m = (r - l)/2 + l;
            if (A[m] < target){
                l = m + 1;
            }else if (A[m] > target){
                r = m - 1;
            }else{
                return m;
            }
        }
        if (target > A[m])
            return m + 1;
        else
            return m;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    int A[] = {2, 4, 6, 7, 10};
    cout << sol.searchInsert(A, 5, 11) << endl;
    return 0;
}