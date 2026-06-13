class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        comp = {}

        for i in range(len(nums)):
            cur_comp = 0 - nums[i]
            if cur_comp in comp:
                comp[cur_comp].append(i)
            else:
                comp[cur_comp] = [i]

        left = 0
        right = len(nums)
        res = []
        used = set()

        while left < len(nums) - 2:
            while right > left + 1:
                right -= 1

                cur_sum = nums[left] + nums[right]

                if cur_sum in comp:
                    
                    third_idx = next((i for i in comp[cur_sum] if i != left and i != right), None)
                    if third_idx is None:
                        continue
                    
                    triplet = [nums[third_idx], nums[left], nums[right]]
                    triplet_set = frozenset(triplet)

                    if triplet_set in used:
                        continue

                    res.append(triplet)
                    used.add(triplet_set)

            left += 1
            right = len(nums)
        
        return res