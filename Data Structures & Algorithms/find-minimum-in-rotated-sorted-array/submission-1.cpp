class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() < 2) return nums[0];

        int l = 0;
        int r = nums.size() - 1;
        int m = (r - l) / 2;
        cout << "Left: " << nums[l] << ", Mid: " << nums[m] << ", Right: " << nums[r] << "\n";

        if (nums[r] < nums[m] && nums[l] < nums[m]) {
            cout << "Middle is greatest \n";
            if (nums[r] < nums[l]){
                l = m;
            } else {
                r = m;
            }
        }
        else if (nums[r] < nums[m]) {
            l = m;
            cout << "Right is smaller than Middle \n";
        }
        else if (nums[l] < nums[m]){
            r = m;
            cout << "Left is smaller than Middle \n";
        }
        else if (nums[l] > nums[r]) {
            r = m;
            cout << "Left is greater than Right \n";
        }
        else if (nums[r] > nums[l]) {
            l = m;
            cout << "Right is greater than Left \n";
        }

        while (r >= l) {
            m = l + (r - l) / 2;
            int mid = nums[m];

            cout << "Left: " << nums[l] << ", Right: " << nums[r] << ", Mid: " << nums[m] << "\n";

            int prev = m - 1;
            if (prev < 0) {
                prev = nums.size() - 1;
            }

            cout << "Prev of mid: " << nums[prev] << "\n";

            if (nums[prev] > mid) {
                return mid;
            }

            if (mid < nums[r]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        cout << "Something went wrong, couldn't find min \n";
        return -1;
    }
};



// 8 0 1 2 3 4 5 6 7

// 7 8 9 10 1 2 3 4