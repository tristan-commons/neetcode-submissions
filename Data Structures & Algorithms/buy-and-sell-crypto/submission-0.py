class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        best_profit = 0

        l = 0
        r = 1

        if len(prices) < 2:
            return 0

        while r < len(prices):
            profit = prices[r] - prices[l]
            best_profit = max(profit, best_profit)
            if profit < 0:
                l = r
            r += 1
        
        return best_profit

# 10, 1, 2, 6, 20, 8