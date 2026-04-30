class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> window;
        int l = 0;
        vector<int> result;

        for (int r = 0; r < nums.size(); r++) {
            window[nums[r]]++;
            cout << to_string(nums[r]) << "\n";

            if (r - l + 1 < k) {
                continue;
            }

            result.push_back(window.rbegin()->first);

            window[nums[l]]--;
            if (window[nums[l]] == 0) {
                window.erase(nums[l]);
            }
            l++;
        }

        return result;
    }
};
