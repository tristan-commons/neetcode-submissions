class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index = {}

        for i in range(len(nums)):
            val = nums[i]
            if val in index:
                index[val].append(i)
            else:
                index[val] = [i]
            
            comp = target - val
            if comp not in index:
                continue
            for ind in index[comp]:
                if ind != i:
                    return [ind, i]
        