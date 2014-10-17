class Solution:
    # @return a list of lists of integers
    def combine(self, n, k):
        self.result = []
        self.n = n
        self.k = k
        buf = []
        self.findCombination(1, 0, buf)
        return self.result

    def findCombination(self, start, length, buf):
        if start > self.n+1:
            return
        if self.k > length+self.n-start +1:
            return
        # print (start,length,buf)
        if length == self.k:
            self.result.append(buf)
            return
        self.findCombination(start+1, length, buf)
        new_buf = buf[:]
        new_buf.append(start)
        self.findCombination(start+1, length+1, new_buf)
        return

if __name__ == '__main__':
    s = Solution()
    print s.combine(4,2)
