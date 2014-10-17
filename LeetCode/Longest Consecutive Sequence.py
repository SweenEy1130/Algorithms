class Solution:
    # @param num, a list of integer
    # @return an integer
    def longestConsecutive(self, num):
        max_len = 0
        num = set(num)
        for item in num:
            l = 0
            left = item-1
            right = item+1
            while left in num:
                l+=1
                num.remove(left)
                left=left-1

            while right in num:
                l+=1
                num.remove(right)
                right=right+1

            num.remove(item)

            if l > max_len:
                max_len = l
        return max_len


if __name__ == '__main__':
    s=Solution()
    num = [100, 4, 200, 1, 3, 2]
    print s.longestConsecutive(num)