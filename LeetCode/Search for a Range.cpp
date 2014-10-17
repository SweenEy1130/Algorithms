#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l = binarySearch(A, n, target - 0.1);
        int r = binarySearch(A, n, target + 0.1);
        vector<int> ans;
        if (A[l] != target){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(l);
        ans.push_back(r);
        return ans;
    }

    int binarySearch(int A[], int n, float target){
        int low = 0, high = n - 1, mid;
        while (low < high){
            mid = (high - low) / 2 + low;
            if (A[mid] < target){
                low = mid+1;
            }else if (A[mid] > target){
                high = mid - 1;
            }else{
                return mid;
            }
        }
        if (A[high] < target) return high+1;
        return low;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    int A[] = {5,7,7,8,8,10}, n = 6, target = 8;
    vector<int> ans = sol.searchRange(A, n, target);
    cout << ans[0] << endl;
    cout << ans[1] << endl;
    return 0;
}