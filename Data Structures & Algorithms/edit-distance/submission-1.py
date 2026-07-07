class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        memo = {}
        
        def helper(i, j):
            if (i, j) in memo:
                return memo[(i, j)]

            if i == len(word1):
                return len(word2) - j
            if j == len(word2):
                return len(word1) - i
            
            if word1[i] == word2[j]:
                ops = helper(i + 1, j + 1)
                memo[(i, j)] = ops
                return ops
            
            min_ops = min(helper(i + 1, j), helper(i, j + 1))
            min_ops = min(min_ops, helper(i + 1, j + 1)) + 1
            memo[(i, j)] = min_ops
            return min_ops
        
        return helper(0, 0)