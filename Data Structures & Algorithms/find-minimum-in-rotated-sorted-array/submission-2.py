class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1

        if len(nums) == 1:
            return nums[0]

        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid - 1] > nums[mid]:
                return nums[mid]
            
            if nums[mid] < nums[r]:
                r = mid
            else:
                l = mid + 1