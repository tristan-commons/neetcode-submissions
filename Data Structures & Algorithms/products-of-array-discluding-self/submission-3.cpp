class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroCount++;
                continue;
            }
            product *= nums[i];
        }

        if (zeroCount > 1) {
            return vector<int>(nums.size(), 0);
        }

        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount > 0) {
                if (nums[i] != 0) {
                    result.push_back(0);
                } else {
                    result.push_back(product);
                }
                continue;
            }

            result.push_back(product / nums[i]);
        }

        return result;
    }
};
