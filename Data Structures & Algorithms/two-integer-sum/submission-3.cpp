class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valueMap;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (valueMap.count(complement) > 0) {
                vector<int> result = {valueMap[complement], i};
                return result;
            }

            valueMap[nums[i]] = i;
        }

        return vector<int>();
    }
};
