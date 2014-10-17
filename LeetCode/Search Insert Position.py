class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        left = 0
        right = len(A)
        while left <= right:
            mid = (right + left) >> 1
            # print (left, mid, right)

            if mid < len(A) and A[mid] > target:
                right = mid - 1
            elif mid < len(A) and A[mid] < target:
                left = mid + 1
            else:
                return mid

        if A[mid] >= target:
            return mid
        else:
            return mid+1

if __name__ == '__main__':
    s = Solution()
    A = [1,3,5,6]
    k = 12
    print s.searchInsert(A,k)
