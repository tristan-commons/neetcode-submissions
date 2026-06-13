class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l = 0
        r = len(heights) - 1

        largest_area = 0

        while r > l:
            area = min(heights[l], heights[r]) * (r - l)
            largest_area = max(area, largest_area)

            if (heights[r] < heights[l]):
                r -= 1
            else:
                l += 1
        
        return largest_area