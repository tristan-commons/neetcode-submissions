class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        order = []
        index = {}

        for i in nums:
            if i not in freq:
                freq[i] = 1
                order.append(i)
                index[i] = len(order) - 1
                print(order)
                continue
            
            freq[i] += 1
            idx = index[i]

            while idx > 0 and freq[order[idx-1]] < freq[i]:
                order.insert(idx-1, order.pop(idx))
                index[order[idx]] = idx
                index[i] -= 1
                idx = index[i]

        
        return order[:k]


