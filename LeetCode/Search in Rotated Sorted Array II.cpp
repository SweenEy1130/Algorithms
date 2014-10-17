class Solution {
public:
    bool search(int A[], int n, int target) {
        int left = 0, right = n-1, mid;

        while (left <= right){
            while(left <= right){
                if (left + 1 < n && A[left] == A[left+1]) left++;
                else if (right - 1 >= 0 && A[right] == A[right-1]) right--;
                else break;
            }
            mid = (right - left) / 2 + left;

            if (target == A[mid])
                return true;
            else if ((A[left] <= A[mid] && target < A[mid] && target >= A[left]) ||
                (A[left] > A[mid] && !(target > A[mid] && target <= A[right])))
                right = mid - 1;
            else if ((A[left] > A[mid] && target > A[mid] && target <= A[right]) ||
                (A[left] <= A[mid] && !(target < A[mid] && target >= A[left])))
                left = mid + 1;
        }

        return false;
    }
};