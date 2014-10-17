class Solution:
	# @return a string
	def longestCommonPrefix(self, strs):
		if len(strs) == 0:
			return ""

		l = len(strs[0])

		for st in strs[1:]:
			l = min(l, len(st))
			i = 0
			while i in range(l):
				if st[i] != strs[0][i]:
					break
				i += 1
			l = i

		return strs[0][:l]

if __name__ == '__main__':
	s = Solution()
	strs = ["string", "street", "stress"]
	print s.longestCommonPrefix(strs)