class Solution:
	# @return a list of lists of length 4, [[val1,val2,val3,val4]]
	def fourSum(self, num, target):
		l = len(num)
		if l < 4:
			return []
		num.sort()
		ans, hashtable = set(), {}
		for i in range(0, l-1):
			for j in range(i+1, l):
				if num[i] + num[j] not in hashtable:
					hashtable[num[i] + num[j]] = [(i,j)]
				else:
					hashtable[num[i] + num[j]].append((i,j))

		for i in range(0, l-1):
			for j in range(i+1, l-2):
				tmp = target - num[i] - num[j]
				if tmp in hashtable:
					for item in hashtable[tmp]:
						# Keep the order i < j < m < n
						if item[0] > j:
							ans.add( ( num[i], num[j], num[item[0]], num[item[1]] ) )

		return [list(i) for i in ans]

if __name__ == '__main__':
	target = 0
	num = [0,0,0,0]
	s = Solution()
	print s.fourSum(num, 0)