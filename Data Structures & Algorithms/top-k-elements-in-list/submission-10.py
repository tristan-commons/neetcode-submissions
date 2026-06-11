class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        buckets = [[] for i in range(len(nums) + 1)]

        for num in nums:
            freq[num] = 1 + freq.get(num, 0)
        
        for num, count in freq.items():
            buckets[count].append(num)
        
        res = []
        for i in range(len(buckets)-1, 0, -1):
            res.extend(buckets[i])
            if len(res) >= k:
                return res[:k]

        