class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index = {}

        for i in range(len(nums)):
            val = nums[i]
            if val in index:
                index[val].append(i)
            else:
                index[val] = [i]
        
        for i in range(len(nums)):
            comp = target - nums[i]
            if comp in index:
                for ind in index[comp]:
                    if ind != i:
                        return [i, ind]
        