class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> uniqueVals;

        for (int i = 0; i < nums.size(); i++) {
            if (uniqueVals.count(nums[i])) {
                return true;
            }

            uniqueVals.insert(nums[i]);
        }

        return false;
    }
};