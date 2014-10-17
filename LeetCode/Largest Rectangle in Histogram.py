class Solution:
    # @param height, a list of integer
    # @return an integer
    def largestRectangleArea(self, height):
        l = len(height)
        if l==0:
            return 0
        indexStack = []
        area = [0] * l
        height.append(0)
        maxArea=0
        i=0
        while i <= l:
            if not indexStack or height[indexStack[-1]] <= height[i]:
                indexStack.append(i)
                i+=1
            else:
                idx = indexStack.pop()
                area[idx] += (i-idx) * height[idx]

        i=l-1
        indexStack = []
        while i >= -1:
            # print indexStack
            if not indexStack or height[indexStack[-1]] <= height[i]:
                indexStack.append(i)
                i-=1
            else:
                idx = indexStack.pop()
                # print idx,i
                area[idx] += (idx - i) * height[idx]
        for i in range(l):    
            area[i] -= height[i] 
        # print area
        return max(area)

if __name__ == '__main__':
    s=Solution()
    print s.largestRectangleArea([1,2,3,1,1,1,1])
    print s.largestRectangleArea( [2,1,5,6,2,3])
    print s.largestRectangleArea([4,2,3])
    



