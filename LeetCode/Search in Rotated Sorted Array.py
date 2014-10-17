class Solution:
	# @param A, a list of integers
	# @param target, an integer to be searched
	# @return an integer
	def search(self, A, target):
		# find the split pos
		low = 0
		high = len(A) - 1
		mid = -1
		while low <= high:
			mid = (low + high) / 2
			if A[mid] > A[low] and A[mid] < A[high]:
				break
			elif A[mid] > A[low]:
				low = mid
			elif A[mid] < A[high]:
				high = mid
			else:
				break

		high = mid
		if mid + 1 < len(A):
			low = mid + 1
		else: low = -1

		if target <= A[high] and target >= A[0]:
			low = 0
		elif low!= -1 and target >= A[low] and target <= A[len(A)-1]:
			high = len(A)-1
		else:
			return -1

		# binary search
		while low <= high:
			mid = (low + high) / 2
			if A[mid] < target:
				low = mid + 1
			elif A[mid] > target:
				high = mid - 1
			else:
				return mid

		return -1

if __name__ == '__main__':
	s = Solution()
	A = [1, 2, 3, 5, 0]
	print s.search([0], 0)