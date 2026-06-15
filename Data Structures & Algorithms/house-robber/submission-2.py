class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        dp = {}
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        for i in range(2, len(nums)):
            dp[i] = max(dp[i-1], nums[i] + dp[i-2])
        
        return dp[len(nums) - 1]

        # dp = {}

        # def helper(i, arr):
        #     if i >= len(arr):
        #         return 0
        #     elif i == len(arr) - 1:
        #         return arr[i]
            
        #     if i in dp:
        #         return dp[i]
            
        #     big = arr[i]
        #     for j in range(i + 2, len(arr)):
        #         big = max(big, arr[i] + helper(j, arr))
        #     dp[i] = big
        #     return big
        
        # return max(helper(0, nums), helper(1, nums))