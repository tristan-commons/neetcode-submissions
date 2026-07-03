class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_s = {}
        max_ns = {}

        def helper(i, started):
            if i == len(nums) - 1:
                return max(0, nums[i]) if started else nums[i]
            if started:
                if i in max_s:
                    return max_s[i]
                cur_max = max(0, nums[i] + helper(i + 1, True))
                max_s[i] = cur_max
                return cur_max
            else:
                if i in max_ns:
                    return max_ns[i]
                cur_max = max(helper(i + 1, False), nums[i] + helper(i + 1, True))
                max_ns[i] = cur_max
                return cur_max
        
        return helper(0, False)
