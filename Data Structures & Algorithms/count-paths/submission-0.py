class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = {}
        
        def helper(x, y, m, n):
            if x >= m or y >= n:
                return 0
            if x == m - 1 and y == n - 1:
                return 1

            if (x, y) in dp:
                return dp[(x, y)]
            
            paths = helper(x+1, y, m, n) + helper(x, y+1, m, n)
            dp[(x, y)] = paths
            return paths
        
        return helper(0, 0, m, n)