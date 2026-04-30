class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int res = 0;
        while (l < r) {
            int lVal = heights[l];
            int rVal = heights[r];
            int area = min(lVal, rVal) * (r - l);
            res = max(area, res);

            if (lVal > rVal) {
                r--;
            } else {
                l++;
            }
        }

        return res;
    }
};
