class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        if len(A)==1:
            return 0

        step = 0
        end = A[0]
        start = 0
        while end < len(A)-1 and start < end:
            step+=1
            tmp = end
            for i in range(start+1 , end+1):
                if (A[i]+i > end):
                    end = A[i] + i
            start = tmp

        return step+1

if __name__ == '__main__':
    s = Solution()
    # A = [3,2,1,0,4]
    A = [2,3,1,2,4]
    A = [2,2,3,2,4]
    A = [2,1]
    # A = [1,1,1,1]
    print s.jump(A)