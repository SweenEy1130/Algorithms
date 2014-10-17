class Solution:
	# @param A, a list of integers
	# @return an integer
	def trap(self, A):
		l = len(A)
		if l < 3:
			return 0
		left = [0] * l
		right = [0] * l

		left[0] = A[0]
		right[l-1] = A[l-1]
		left[0] = 0
		right[l-1] = 0

		for i in range(1, l):
			left[i] = max(left[i-1], A[i-1])

		for i in range(l-2, -1, -1):
			right[i] = max(right[i+1], A[i+1])

		water = 0
		for i in range(0, l):
			fill = min(left[i], right[i]) - A[i]
			if fill > 0:
				water += fill

		return water

if __name__ == '__main__':
	s = Solution()
	# A = [0,1,0,2,1,0,1,3,2,1,2,1]
	A = [5,2,1,2,1,5]
	print s.trap(A)