class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        heap = []

        for num in nums:
            freq[num] = 1 + freq.get(num, 0)
        
        for num in freq.keys():
            heapq.heappush(heap, (freq[num], num))
            if len(heap) > k:
                heapq.heappop(heap)
        
        return [n[1] for n in heap]


