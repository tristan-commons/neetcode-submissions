class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        tracker = set(nums)

        if len(nums) == 0:
            return 0

        longest = 1
        cur_length = 1

        for n in nums:
            if n not in tracker:
                continue

            cur = n
            while cur + 1 in tracker:
                cur_length += 1
                tracker.remove(cur)
                cur = cur + 1
            tracker.remove(cur)
            
            cur = n
            while cur - 1 in tracker:
                cur_length +=1
                if cur in tracker:
                    tracker.remove(cur)
                cur = cur - 1
            if cur in tracker:
                tracker.remove(cur)

            longest = max(cur_length, longest)
            cur_length = 1
            

        
        return longest