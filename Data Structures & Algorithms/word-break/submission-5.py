class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:

        dp = [False] * (len(s) + 1)

        dp[len(s)] = True

        for i in range(len(s) - 1, -1, -1):
            for w in wordDict:
                if i + len(w) <= len(s) and s[i:i + len(w)] == w:
                    dp[i] = dp[i + len(w)]
                if dp[i]:
                    break
        
        return dp[0]


        # memo = {}

        # def helper(l, r):
        #     cur_word = s[l:r + 1]

        #     if cur_word in memo:
        #         return memo[cur_word]

        #     if r >= len(s) - 1:
        #         if cur_word in words:
        #             return True
        #         else:
        #             return False
            
        #     result = False
        #     if cur_word in words:
        #         result = helper(r+1, r+1) or helper(l, r+1)
        #     else:
        #         result = helper(l, r+1)
        #     memo[cur_word] = result
        #     return result
        # return helper(0, 0)
