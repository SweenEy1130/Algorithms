class Solution:
    # @return an integer
    def maxArea(self, height):
        l=0
        r=len(height) - 1
        maxArea=0

        while (l < r):
            # print (l,r)
            maxArea = max(maxArea, min(height[l],height[r]) * (r-l))
            if height[l] > height[r]:
                k = r - 1
                while k > l and height[k]<=height[r]:
                    k-=1
                r=k
            else:
                k = l + 1
                while k < r and height[k]<=height[l]:
                    k+=1
                l=k
        return maxArea

if __name__ == '__main__':
    s = Solution()
    print s.maxArea([4,6,2,6,7,11,2])
    print s.maxArea([])

