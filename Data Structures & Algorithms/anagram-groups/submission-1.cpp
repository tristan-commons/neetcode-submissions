class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // Map of type: map, vector<int>
        // Key is freq map, value is list of indices
        // Loop through the map, each key value pair represents a group of anagrams

        map<map<char, int>, vector<int>> groupMap;

        for (int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            map<char, int> freqMap;

            for (int j = 0; j < word.length(); j++) {
                freqMap[word[j]]++;
            }

            if (groupMap.count(freqMap) > 0) {
                groupMap[freqMap].push_back(i);
            } else {
                groupMap[freqMap] = {i};
            }
        }

        vector<vector<string>> result;

        for (auto element : groupMap) {
            vector<int>& indices = element.second;
            vector<string> group;
            for (int i = 0; i < indices.size(); i++) {
                group.push_back(strs[indices[i]]);
            }
            result.push_back(group);
        }

        return result;
    }
};
