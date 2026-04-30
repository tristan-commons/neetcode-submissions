class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;

        int maxProfit = 0;
        while (r < prices.size()) {
            int buy = prices[l];
            int sell = prices[r];

            if (buy > sell) {
                l = r;
            } else {
                maxProfit = max(sell - buy, maxProfit);
            }
            r++;
        }

        return maxProfit;
    }
};
