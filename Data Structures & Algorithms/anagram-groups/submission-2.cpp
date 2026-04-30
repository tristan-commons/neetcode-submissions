class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> groupMap;

        for (int i = 0; i < strs.size(); i++) {
            vector<int> freqMap (26, 0);
            for (int j = 0; j < strs[i].length(); j++) {
                freqMap[strs[i][j] - 'a']++;
            }
            groupMap[freqMap].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for (const auto& element : groupMap) {
            result.push_back(element.second);
        }

        return result;
    }
};
