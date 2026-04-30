class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        map<int, vector<int>> orderedMap;

        for (int i = 0; i < nums.size(); i++) {
            freqMap[nums[i]]++;
        }

        for (const auto& element : freqMap) {
            orderedMap[-element.second].push_back(element.first);
        }

        vector<int> result;

        int i = 0;
        for (const auto& element : orderedMap) {
            vector<int> values = element.second;
            for (int j = 0; j < values.size(); j++) {
                if (i >= k) {
                    break;
                }
                result.push_back(values[j]);
                i++;
            }
        }

        return result;
    }
};
