class Solution {
public:
    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size() - 1);
    }

    int helper(vector<int>& nums, int target, int l, int r) {
        if (r < l) return -1;

        int n = r - l;
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (target > nums[mid]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }

        return helper(nums, target, l, r);
    }
};
