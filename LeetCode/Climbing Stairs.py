class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        f = [0] * n
        f[0] = 1
        if n==1:
            return f[0]
        f[1] = 2
        if n==2:
            return f[1]
        for i in range(2, n):
            f[i] = f[i-1] + f[i-2]

        return f[n-1]

if __name__ == '__main__':
    s = Solution()
    print s.climbStairs(3)
