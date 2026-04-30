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

        for (const auto& element : orderedMap) {
            vector<int> values = element.second;
            for (int j = 0; j < values.size(); j++) {
                result.push_back(values[j]);
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
