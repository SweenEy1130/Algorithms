class Solution:
	# @return a list of strings, [s1, s2]
	def letterCombinations(self, digits):
		self.dic = [
			[],
			['a','b','c'],
			['d','e','f'],
			['g','h','i'],
			['j','k','l'],
			['m','n','o'],
			['p','q','r','s'],
			['t','u','v'],
			['w','x','y','z']
		]
		self.digits = digits
		self.l = len(digits)
		return self.generate([""],0)

	def generate(self, ans, d):
		if d >= self.l:
			return ans
		res = []
		for ch in self.dic[int(self.digits[d]) - 1]:
			for item in ans:
				res.append(item + ch)
		res = self.generate(res, d + 1)

		return res

if __name__ == '__main__':
	s = Solution()
	print s.letterCombinations("")