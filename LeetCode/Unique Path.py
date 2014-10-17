class Solution:
    # @return an integer
    def uniquePaths(self, m, n):
        rnd = max(m,n) * 2
        f = [[0 for col in range(m)] for row in range(n)]
        f[0][0] = 1
        for i in range(1, rnd - 1):
            for j in range(0, i+1):
                if j >= 0 and j < n and i-j >= 0 and i-j < m:
                    if j-1 >= 0:
                        f[j][i-j] += f[j-1][i-j] 
                    if i-j-1 >= 0:
                        f[j][i-j] += f[j][i-j-1]
        # print f
        return f[n - 1][m - 1] 

if __name__ == '__main__':
    s = Solution()
    print s.uniquePaths(6,4)