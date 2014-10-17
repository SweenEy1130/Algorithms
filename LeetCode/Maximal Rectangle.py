class Solution:
    # @param matrix, a list of lists of 1 length string
    # @return an integer
    def maximalRectangle(self, matrix):
        h = len(matrix)
        if h == 0:
            return 0
        l = len(matrix[0])
        if l == 0:
            return 0
        maxArea = 0
        height = [0] * (l+1)

        for i in range(h):
            for j in range(l):
                if matrix[i][j] == '0':
                    height[j] = 0
                else:
                    height[j] += 1
            area = [0] * (l+1)
            indexStack = []
            k = 0
            while k <= l:
                if not indexStack or height[indexStack[-1]] <= height[k]:
                    indexStack.append(k)
                    k += 1
                else:
                    idx = indexStack.pop()
                    area[idx] += (k-idx) * height[idx]
            k = l - 1
            indexStack = []
            while k >= -1:
                if not indexStack or height[indexStack[-1]] <= height[k]:
                    indexStack.append(k)
                    k -= 1
                else:
                    idx = indexStack.pop()
                    area[idx] += (idx - k) * height[idx]

            for k in range(l):
                area[k] -= height[k]

            maxArea = max(maxArea, max(area))

        return maxArea

if __name__ == '__main__':
    s=Solution()
    matrix = [
        ['0','0','0','1'],
        ['0','0','1','0'],
        ['0','0','1','1'],
        ['0','0','1','1']
    ]
    print s.maximalRectangle([['0']])
