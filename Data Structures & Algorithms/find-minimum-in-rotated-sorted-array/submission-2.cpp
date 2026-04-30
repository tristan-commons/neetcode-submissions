class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() < 2) return nums[0];

        int l = 0;
        int r = nums.size() - 1;
        int m = (r - l) / 2;

        if (nums[r] < nums[m] && nums[l] < nums[m]) {
            if (nums[r] < nums[l]){
                l = m;
            } else {
                r = m;
            }
        }
        else if (nums[r] < nums[m]) {
            l = m;
        }
        else if (nums[l] < nums[m]){
            r = m;
        }
        else if (nums[l] > nums[r]) {
            r = m;
        }
        else if (nums[r] > nums[l]) {
            l = m;
        }

        while (r >= l) {
            m = l + (r - l) / 2;
            int mid = nums[m];

            int prev = m - 1;
            if (prev < 0) {
                prev = nums.size() - 1;
            }

            if (nums[prev] > mid) {
                return mid;
            }

            if (mid < nums[r]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};