#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int jump(int A[], int n) {
        int idx = 0, level = 0, maxLength = 0;
        if (n == 1) return 0;
        while (idx < n){
            level++;
            if (level >= n) return 0;
            int i = idx, range = min(maxLength, n-1);
            while (i <= range){
                maxLength = max(maxLength, i + A[i]);
                if (maxLength >= n-1)
                    return level;
                i++;
            }
            idx = i;
        }
        return 0;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    int A[]= {3,4,3,1,0,0,0,3,0,2,0,3}, n = 12;
    cout << sol.jump(A, n) << endl;
    return 0;
}