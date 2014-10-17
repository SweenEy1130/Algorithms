class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0, right = n-1, mid;

        while (left <= right){
            mid = (right - left) / 2 + left;

            if (target == A[mid])
                return mid;
            else if ((A[left] <= A[mid] && target < A[mid] && target >= A[left]) ||
                (A[left] > A[mid] && !(target > A[mid] && target <= A[right])))
                right = mid - 1;
            else if ((A[left] > A[mid] && target > A[mid] && target <= A[right]) ||
                (A[left] <= A[mid] && !(target < A[mid] && target >= A[left])))
                left = mid + 1;
        }

        return -1;
    }
};