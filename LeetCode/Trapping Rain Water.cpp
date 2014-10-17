#include <iostream>
using namespace std;
class Solution {
public:
    int trap(int A[], int n) {
        int * left = new int[n];
        int * right = new int[n];
        left[0] = 0;
        right[n-1] = 0;
        for (int i = 1; i < n; ++i)
            left[i] = max(left[i-1], A[i-1]);

        for (int i = n-2; i >= 0; --i)
            right[i] = max(right[i+1], A[i+1]);

        int water = 0;
        for (int i = 0; i < n; ++i)
            if (min(left[i], right[i]) > A[i]){
                water += min(left[i], right[i]) - A[i];
            }

        return water;
    }
};

int main(int argc, char const *argv[])
{
    int A[] = {2,1,0,2}, n = 4;
    Solution sol;
    cout << sol.trap(A, n) << endl;
    return 0;
}