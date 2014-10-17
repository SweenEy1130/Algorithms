#include <iostream>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = ans ^ A[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    int A[] = {1,1,3,3,5};
    cout << sol.singleNumber(A, 5) << endl;
    return 0;
}