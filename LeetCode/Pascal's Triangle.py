class Solution:
	# @return a list of lists of integers
	def generate(self, numRows):
		ans=[]
		if numRows == 0:
			return ans
		ans = [[1]]
		l = 2
		for i in range(1, numRows):
			cursor = 0
			ans.append([])
			for j in range(0, l):
				if j == 0:
					t = ans[i-1][0]
				elif j == l - 1:
					t = ans[i-1][l-2]
				else:
					t = ans[i-1][j] + ans[i-1][j-1]
				ans[i].append(t)
			l += 1
		return ans

if __name__ == '__main__':
	s = Solution()
	print s.generate(10)
