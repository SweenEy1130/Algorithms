#!/usr/bin/python
# -*- coding: utf-8 -*-
class Solution:
	# @param matrix, a list of lists of integers
	# @param target, an integer
	# @return a boolean
	def searchMatrix(self, matrix, target):
		if len(matrix) == 0:
			return False
		low = 0
		height = len(matrix) - 1
		mid = 0
		while low <= height:
			mid = (low + height) / 2
			if matrix[mid][0] < target:
				low = mid + 1
			elif matrix[mid][0] > target:
				height = mid - 1
			else:
				break;
		if matrix[mid][0] > target:
			mid -= 1

		line = mid
		low = 0
		height = len(matrix[0]) - 1
		while low <= height:
			mid = (low + height) / 2
			if matrix[line][mid] < target:
				low = mid + 1
			elif matrix[line][mid] > target:
				height = mid - 1
			else:
				return True

		return False

if __name__ == "__main__":
	matrix = [
		[1,   3,  5,  7],
		[10, 11, 16, 20],
		[23, 30, 34, 50]
	]
	s = Solution()
	print s.searchMatrix(matrix, 35)