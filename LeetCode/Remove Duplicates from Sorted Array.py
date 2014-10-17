class Solution:
	# @param a list of integers
	# @return an integer
	def removeDuplicates(self, A):
		i = 0
		l = len(A)
		k = 0
		for i in range(0, l):
			if i+1 < l and A[i] != A[i+1]:
				A[k]=A[i]
				k+=1
		A[k]=A[l-1]
		return k+1

if __name__ == '__main__':
	s = Solution()
	A = [1,1,1,3,3,4,4,5,6,6,7,7,7]
	print s.removeDuplicates(A)
	print A