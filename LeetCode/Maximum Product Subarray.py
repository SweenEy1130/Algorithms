class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxProduct(self, A):
        l = len(A)
        f1 = [0] * l
        f2 = [0] * l

        if A[0] > 0:
            f1[0] = A[0]
        else:
            f2[0] = A[0]

        ans = A[0]
        for i in range(1, l):
            f1[i] = max(A[i] * f1[i-1], A[i] * f2[i-1], A[i])
            f2[i] = min(A[i] * f1[i-1], A[i] * f2[i-1], A[i])
            ans = max(f1[i], ans)

        return ans
