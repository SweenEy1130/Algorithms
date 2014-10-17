class Solution:
	# @param A a list of integers
	# @return an integer
	def removeDuplicates(self, A):
		l = len(A)
		k = 0
		counter = 1
		for i in range(l):
			if (counter < 0 and i+1 < l and A[i] != A[i+1] ):
				counter = 1
			elif counter >= 0 and i+1 < l and A[i] != A[i+1]:
				A[k] =A[i]
				k+=1
				counter = 1
			elif (counter >= 0):
				A[k] = A[i]
				k += 1
				counter -= 1

		return k

if __name__ == '__main__':
	s = Solution()
	print s.removeDuplicates([0,1,1,1,2,2])
	print s.removeDuplicates([0,0])
	print s.removeDuplicates([0])
	print s.removeDuplicates([])
