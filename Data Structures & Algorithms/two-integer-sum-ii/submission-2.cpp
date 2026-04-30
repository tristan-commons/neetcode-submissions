class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size() - 1; i++) {
            int cur = numbers[i];
            int complement = target - cur;

            for (int j = i + 1; j < numbers.size(); j++) {
                int other = numbers[j];
                if (other == complement) {
                    return {i + 1, j + 1};
                }
            }
        }

        return {};
    }
};
