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
            if nums[l - 1] > nums[l]:
                return nums[l]
            
            if nums[mid] < nums[l]:
                r = mid - 1
            else:
                l = mid + 1