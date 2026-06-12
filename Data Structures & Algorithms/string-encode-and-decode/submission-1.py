class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for string in strs:
            length = str(len(string))
            digits = str(len(length))
            res += digits + length + string
        return res

    def decode(self, s: str) -> List[str]:
        res = []

        i = 0
        while i < len(s):
            digits = int(s[i])
            length = int(s[i+1:i+1+digits])
            start = i + 1 + digits
            res.append(s[start:start+length])
            i = start + length
        
        return res
