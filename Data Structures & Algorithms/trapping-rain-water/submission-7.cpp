class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int newVal;
        int curMin = min(height[l], height[r]);
        int curMax = max(height[l], height[r]);

        int filledSpace = 0;
        int area = curMin * (r - l - 1);

        if (height[l] < height[r]) {
            l++;
            newVal = height[l];
        }
        else {
            r--;
            newVal = height[r];
        }

        while (l < r) {
            if (newVal <= curMin) {
                filledSpace += newVal;
            }
            else if (newVal >= curMax) {
                filledSpace += curMin;
                area += (curMax - curMin) * (r - l - 1);
                curMin = curMax;
                curMax = newVal;
            }
            else {
                filledSpace += curMin;
                area += (newVal - curMin) * (r - l - 1);
                curMin = newVal;
            }


            if (height[l] < height[r]) {
                l++;
                newVal = height[l];
            }
            else {
                r--;
                newVal = height[r];
            }
        }

        return max(area - filledSpace, 0);
    }
};
