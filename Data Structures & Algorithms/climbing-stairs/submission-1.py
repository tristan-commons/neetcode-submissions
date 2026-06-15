class Solution:
    def climbStairs(self, n: int) -> int:
        step_map = {}
        return self.climb(0, n, step_map)
        
    def climb(self, cur, end, step_map):
        if cur == end:
            return 1
        if cur > end:
            return 0
        if cur in step_map:
            return step_map[cur]
        
        one = self.climb(cur+1, end, step_map)
        two = self.climb(cur+2, end, step_map)
        step_map[cur] = one + two
        return one + two