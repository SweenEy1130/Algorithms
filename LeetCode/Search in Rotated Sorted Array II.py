class Solution:
	# @param A a list of integers
	# @param target an integer
	# @return a boolean
	def search(self, A, target):
		# find the split pos
		low = 0
		high = len(A) - 1
		mid = -1

		while low <= high:
			while high-1 >= 0 and A[high] == A[high-1]:
				high -= 1
			mid = (low + high) / 2
			# print (low, high)
			if A[mid] > A[low] and A[mid] < A[high]:
				break
			elif A[mid] > A[low]:
				low = mid
			elif A[mid] < A[high]:
				high = mid
			else:
				break

		while mid+1 < len(A) and A[mid+1] >= A[mid]:
			mid += 1

		high = mid
		if mid + 1 < len(A):
			low = mid + 1
		else: low = -1

		if target <= A[high] and target >= A[0]:
			low = 0
		elif low!= -1 and target >= A[low] and target <= A[len(A)-1]:
			high = len(A)-1
		else:
			return False

		# binary search
		while low <= high:
			mid = (low + high) / 2
			if A[mid] < target:
				low = mid + 1
			elif A[mid] > target:
				high = mid - 1
			else:
				return True

		return False

if __name__ == '__main__':
	s = Solution()
	A = [1, 2, 3, 5, 5, 5, 0]
	print s.search([1, 2, 3, 5, 5, 5, 0, 1], 5)
	print s.search([5, 5, 5], 3)
	print s.search([5, 5, 1, 1, 5, 5], 5)
	print s.search([11], 5)
	print s.search([3,0,0,1,2,2], 3)