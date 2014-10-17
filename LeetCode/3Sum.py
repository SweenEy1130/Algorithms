class Solution:
	# @return a list of lists of length 3, [[val1,val2,val3]]
	def threeSum(self, num):
		l = len(num)
		if l == 0:
			return []
		num.sort()
		ans = set()
		for i in range(0, l-2):
			j = i + 1
			k = l - 1	
			while k > j:
				sum3 = num[i] + num[j] + num[k]
	
				if (sum3 == 0):
					ans.add((num[i], num[j], num[k])) 
					j += 1
					k -= 1
				elif (sum3 > 0):
					k -= 1
				elif (sum3 < 0):
					j += 1

		return [list(i) for i in ans]


if __name__ == '__main__':
	num = [-1, 0, 1, 2, -1, -4]
	s = Solution()
	print s.threeSum(num)
