class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = set(wordDict)

        memo = {}

        def helper(l, r):
            if (l, r) in memo:
                return memo[(l, r)]

            cur_word = s[l:r + 1]
            
            if r >= len(s) - 1:
                if cur_word in words:
                    return True
                else:
                    return False
            
            result = False
            if cur_word in words:
                result = helper(r+1, r+1) or helper(l, r+1)
            else:
                result = helper(l, r+1)
            memo[(l, r)] = result
            return result
        return helper(0, 0)
