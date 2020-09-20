class Solution:
	def maxProductPath(self, grid: List[List[int]]) -> int:
		r = len(grid)
		c = len(grid[0])
		dp = [[(0, 0) for i in range(c)] for j in range(r)]
		dp[0][0] = (grid[0][0], grid[0][0])
		for j in range(c - 1):
			dp[0][j + 1] = (grid[0][j + 1] * dp[0][j][0], grid[0][j + 1] * dp[0][j][1])
		for i in range(r - 1):
			dp[i + 1][0] = (grid[i + 1][0] * dp[i][0][0], grid[i + 1][0] * dp[i][0][1])
		for i in range(1, r):
			for j in range(1, c):
				a = min(grid[i][j] * dp[i - 1][j][0], grid[i][j] * dp[i][j - 1][0], grid[i][j] * dp[i - 1][j][1], grid[i][j] * dp[i][j - 1][1])
				b = max(grid[i][j] * dp[i - 1][j][0], grid[i][j] * dp[i][j - 1][0], grid[i][j] * dp[i - 1][j][1], grid[i][j] * dp[i][j - 1][1])
				dp[i][j] = (a, b)
		if dp[-1][-1][1] >= 0:
			return dp[-1][-1][1] % (10 ** 9 + 7)
		else:
			return -1