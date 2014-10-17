class Solution:
	# @param grid, a list of lists of integers
	# @return an integer
	def minPathSum(self, grid):
		if grid == []:
			return 0
		nrow = len(grid)
		ncol = len(grid[0])
		level = nrow + ncol - 1
		f = [[9999999 for col in range(ncol)] for row in range(nrow)]
		f[0][0]  = grid[0][0]
		for i in range(1, level):
			for j in range(i+1):
				if not self.inMat(i-j, j, nrow, ncol):
					continue
				if i-j == 0:
					f[i - j][j] = f[i-j][j-1]
				elif j == 0:
					f[i-j][j] = f[i-j-1][j]
				else:
					f[i-j][j] = min(f[i-j][j-1], f[i-j-1][j])

				f[i-j][j] += grid[i-j][j]
				
		return f[nrow-1][ncol-1]

	def inMat(self, x, y, row, col):
		if x >= row or y >=col:
			return False
		else: return True

if __name__ == '__main__':
	s = Solution()
	matrix = [[1,2],[5,6],[1,1]]
	print s.minPathSum(matrix)