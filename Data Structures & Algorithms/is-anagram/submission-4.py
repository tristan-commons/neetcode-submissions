class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq = {}

        for l in s:
            freq[l] = freq[l]+1 if l in freq else 1

        
        for l in t:
            if l not in freq:
                return False
            
            freq[l] -= 1
            if freq[l] == 0:
                del freq[l]
        
        return len(freq) == 0

