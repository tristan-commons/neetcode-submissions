class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n

        step_map = {}

        step_map[1] = 1
        step_map[2] = 2

        for i in range(3, n + 1):
            step_map[i] = step_map[i - 1] + step_map[i - 2]
        
        return step_map[n]