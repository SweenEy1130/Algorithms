class Solution:
	# @param an integer
	# @return a list of string
	def generateParenthesis(self, n):
		if n == 1:
			return ["()"]

		pattern = []

		subpat = self.generateParenthesis(n - 1)
		for item in subpat:
			pattern.append("("+item+")")
			pattern.append("()" + item)
			if (item+"()") not in pattern:
				pattern.append(item + "()")
		
		return pattern

if __name__ == '__main__':
	s = Solution()
	print s.generateParenthesis(4)