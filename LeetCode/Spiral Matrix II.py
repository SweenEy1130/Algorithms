class Solution:
	# @return a list of lists of integer
	def generateMatrix(self, n):
		mat = [[-1 for col in range(n)] for row in range(n)]
		# 1 for right, 2 for left, 3 for up, 4 for down
		direction = 1
		x, y = 0, 0
		for i in range(n * n):
			mat[x][y] = i+1
			if direction == 1:
				if y+1 >= n or mat[x][y+1] != -1:
					direction = 4
					x += 1
				else:
					y += 1
			elif direction == 2:
				if y-1 < 0 or mat[x][y-1] != -1:
					direction = 3
					x -= 1
				else:
					y -= 1
			elif direction == 3:
				if x-1 < 0 or mat[x-1][y] != -1:
					direction = 1
					y += 1
				else:
					x -= 1
			elif direction == 4:
				if x+1 >= n or mat[x+1][y] != -1:
					direction = 2
					y -= 1
				else:
					x += 1
		return mat

if __name__ == '__main__':
	s = Solution()
	print s.generateMatrix(3)