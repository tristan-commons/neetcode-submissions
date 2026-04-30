class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = r / 2;

        while (true) {
            cout << "Left: " << nums[l] << ", Mid: " << nums[mid] << ", Right: " << nums[r] << "\n";
            if (nums[mid] == target) return mid;
            if (nums[l] == target) return l;
            if (nums[r] == target) return r;
            if (r - l < 2) break;

            if (nums[l] < nums[mid]) {
                if (nums[l] <= target && nums[mid] >= target) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            else if (nums[r] > nums[mid]) {
                if (nums[mid] <= target && nums[r] >= target) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }

            mid = (l + r) / 2;
        }

        return -1;
    }
};



