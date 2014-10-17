class Solution:
	# @return an integer
	def lengthOfLongestSubstring(self, s):
		l = len(s)
		if l == 0:
			return 0
		f = [1] * l
		mstr = 1
		for i in range(1, l):
			t = f[i-1]
			flag = True

			for j in range(0, t):
				if s[i-j-1] == s[i]:
					flag = False
					f[i] += j
					break;
			if flag:
				f[i] += t
				if mstr < f[i]:
					mstr = f[i]
		return mstr

if __name__ == '__main__':
	s = Solution()
	st = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco"
	st = "abcabcbb"
	print s.lengthOfLongestSubstring(st)