class Solution:
	# @return a list of lists of length 4, [[val1,val2,val3,val4]]
	def fourSum(self, num, target):
		l = len(num)
		if l == 0:
			return []
		num.sort()
		ans = []
		for i in range(0, l-3):
			for j in range(i+1, l-2):
				m = j + 1
				n = l - 1
	
				while n > m:
					sum4 = num[i] + num[j] + num[m] + num[n]
	
					if (sum4 == target):
						res = [num[i], num[j], num[m], num[n]]
						if res not in ans:
							ans.append(res) 
						m += 1
						n -= 1
					elif (sum4 > target):
						n -= 1
					elif (sum4 < target):
						m += 1

		return ans


if __name__ == '__main__':
	target = 1
	num = [1, 0, -1, 0, -1, 0]
	s = Solution()
	print s.fourSum(num, 0)