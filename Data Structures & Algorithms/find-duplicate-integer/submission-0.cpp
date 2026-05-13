class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> history = {};

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (history.count(num)) {
                return num;
            }
            history.insert(num);
        }
    }
};
