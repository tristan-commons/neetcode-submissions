class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int max = 0;
        while (l < r) {
            int lVal = heights[l];
            int rVal = heights[r];
            int volume = min(lVal, rVal) * (r - l);
            max = volume > max ? volume : max;

            if (lVal > rVal) {
                r--;
            } else {
                l++;
            }
        }

        return max;
    }
};
