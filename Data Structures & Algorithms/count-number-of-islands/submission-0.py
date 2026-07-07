class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        directions = [[-1, 0], [0, -1], [1, 0], [0, 1]]

        def dfs(stack: List):
            while len(stack) > 0:
                val = stack.pop()
                i = val[0]
                j = val[1]
                grid[i][j] = "0"
                for di, dj in directions:
                    ni = i + di
                    nj = j + dj
                    if ni < 0 or ni >= len(grid):
                        continue
                    if nj < 0 or nj >= len(grid[ni]):
                        continue
                    if grid[i+di][j+dj] == "1":
                        stack.append((i+di, j+dj))


        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "1":
                    res += 1
                    stack = [(i, j)]
                    dfs(stack)
        
        return res

                
                    