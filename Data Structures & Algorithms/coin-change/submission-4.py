class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        memo = {}

        def helper(cur_sum):
            if cur_sum == amount:
                return 0
            if cur_sum > amount:
                return 1e9
            if cur_sum in memo:
                return memo[cur_sum]
            
            steps = int(1e9)
            for c in coins:
                steps = min(steps, 1 + helper(cur_sum + c))
            
            memo[cur_sum] = steps
            return steps
        
        res = helper(0)
        return -1 if res >= int(1e9) else res