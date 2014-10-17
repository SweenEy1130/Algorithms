class Solution {
public:
    bool canJump(int A[], int n) {
        int maxLength = 0;
        for (int i = 0; i < n; ++i)
            if (maxLength >= i)
                maxLength = max(maxLength, A[i] + i);

        if (maxLength >= n-1)
            return true;
        else
            return false;
    }
};