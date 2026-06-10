class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        item_set = set()

        for num in nums:
            if num in item_set:
                return True
            item_set.add(num)
        
        return False