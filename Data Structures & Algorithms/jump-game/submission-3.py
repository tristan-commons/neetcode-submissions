class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [False] * n

        dp[n - 1] = True

        goal = n - 1

        for i in range(n - 2, -1, -1):
            if nums[i] >= goal - i:
                dp[i] = True
                goal = i
            
        
        return dp[0]
