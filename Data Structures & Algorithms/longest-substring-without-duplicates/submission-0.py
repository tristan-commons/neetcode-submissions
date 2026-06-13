class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) < 2:
            return len(s)
        
        l = 0
        r = 0
        last_l = False

        longest = 1
        
        chars = {}
        while r < len(s):
            if not last_l:
                chars[s[r]] = chars.get(s[r], 0) + 1

            if chars.get(s[r], 0) > 1:
                chars[s[l]] -= 1
                if chars[s[l]] == 0:
                    chars.pop(s[l])
                l += 1
                last_l = True
            else:
                longest = max(longest, r - l + 1)
                last_l = False
                r += 1
            
        
        #pfdwwk
        return longest