class Solution:
	# @param A, a list of integers
	# @param target, an integer to be searched
	# @return a list of length 2, [index1, index2]
	def searchRange(self, A, target):
		l = self.binary(A, target-0.1)

		if l >= len(A) or A[l] != target:
			return [-1,-1]

		r = self.binary(A, target+0.1) - 1

		return [l, r]

	def binary(self, A, target):
		low = 0
		high = len(A) - 1

		mid = 0
		while low <= high:
			mid = (low + high) / 2
			if A[mid] > target:
				high = mid - 1
			elif A[mid] < target:
				low = mid + 1
			else:
				return mid
		return low

if __name__ == '__main__':
	s = Solution()
	A = [5, 7, 7, 8, 8]
	target = 8
	print s.searchRange(A, target)
