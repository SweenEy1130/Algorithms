class Solution:
    # @param A, a list of integers
    # @return a boolean
    def canJump(self, A):
        if len(A)==1:
            return True

        f = [-1] * len(A)
        f[0] = A[0]
        for i in range(1, len(A)):
            if f[i-1] > 0:
                f[i] = max(A[i], f[i-1]-1)
            else:
                f[i] = -1
        # print f
        return f[len(A)-1] >= 0

if __name__ == '__main__':
    s = Solution()
    # A = [3,2,1,0,4]
    A = [2,3,1,1,4]
    print s.canJump(A)