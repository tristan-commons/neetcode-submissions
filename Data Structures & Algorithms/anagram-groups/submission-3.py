class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = {}
        for word in strs:
            freq = self.makeFreqSet(word)
            if freq in anagrams:
                anagrams[freq].append(word)
            else:
                anagrams[freq] = [word]
        
        return list(anagrams.values())
        

    def makeFreqSet(self, string: str) -> frozenset[tuple[str, int]]:
        freq = {}

        for char in string:
            freq[char] = freq[char]+1 if char in freq else 1
        
        return frozenset(freq.items())