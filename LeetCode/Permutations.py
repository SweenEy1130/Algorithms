class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permute(self, num):
        length = len(num)
        if length == 0: return []
        if length == 1: return [num]
        res = []
        for i in xrange(length):
            for j in self.permute(num[0:i] + num[i+1:]):
                res.append([num[i]] + j)
        return res

if __name__ == '__main__':
    s = Solution()
    print s.permute([1,1,2])