class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        nums_max = {}

        def helper(i, started):
            if i in nums_max:
                return nums_max[i]

            if i == len(nums) - 1:
                return max(0, nums[i]) if started else nums[i]
            if started:
                cur_max = max(0, nums[i] + helper(i + 1, True))
                nums_max[i] = cur_max
                return cur_max
            else:
                return max(helper(i + 1, False), nums[i] + helper(i + 1, True))
        
        return helper(0, False)
