class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (r >= l) {
            int mid = l + (r - l) / 2;
            cout << mid << ", l: " << l << ", r: " << r << "\n";
            if (nums[mid] == target) {
                return mid;
            }

            if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return -1;
    }
};
