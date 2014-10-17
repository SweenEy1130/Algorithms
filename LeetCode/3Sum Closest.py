class Solution:
	# @return an integer
	def threeSumClosest(self, num, target):
		num.sort()
		l = len(num)
		minError = 999999
		sumError = 0
		# print num
		for i in range(0, l-2):
			j = i + 1
			k = l - 1

			while k > j:
				sumThree = num[i] + num[j] + num[k]
				if minError > abs(sumThree - target):
					minError = abs(sumThree - target)
					sumError = sumThree
				if (sumThree == target):
					return target
				elif (sumThree > target):
					k -= 1
				elif (sumThree < target):
					j += 1

		return sumError


if __name__ == '__main__':
	target = 1
	num = [-1, 2, 1, -4, -5,-2]
	s = Solution()
	print s.threeSumClosest(num, target)