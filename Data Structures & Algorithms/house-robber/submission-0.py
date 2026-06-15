class Solution:
    def rob(self, nums: List[int]) -> int:

        dp = {}

        def helper(i, arr):
            if i >= len(arr):
                return 0
            elif i == len(arr) - 1:
                return arr[i]
            
            if i in dp:
                return dp[i]
            
            big = arr[i]
            for j in range(i + 2, len(arr)):
                big = max(big, arr[i] + helper(j, arr))
            dp[i] = big
            return big
        
        return max(helper(0, nums), helper(1, nums))