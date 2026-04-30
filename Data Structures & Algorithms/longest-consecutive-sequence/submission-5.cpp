class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values;
        int n = nums.size();

        for (const auto& num : nums) {
            values.insert(num);
        }

        int max = 0;
        for (const auto& val : values) {
            if (values.count(val - 1)) {
                continue;
            }

            int seq = 0;
            int cur = val;
            while (seq <= n) {
                if (values.count(cur)) {
                    seq++;
                    cur++;
                } else {
                    break;
                }
            }

            max = seq > max ? seq : max;
        }

        return max;

    }
};
