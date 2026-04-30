class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;

        unordered_map<char,int> s1Freq;
        unordered_map<char,int> s2Freq;

        // generate frequency map for s1
        // Sliding window of size of s1 in s2
        // Modify frequency map of window as s2 moves & compare it with s1 until match is found

        for (const auto& letter : s1) {
            s1Freq[letter]++;
        }

        int l = 0;
        for (int r = 0; r < s2.length(); r++) {
            s2Freq[s2[r]]++;
            if (r - l + 1 < s1.length()) {
                continue;
            }

            if (s1Freq == s2Freq) {
                return true;
            }

            s2Freq[s2[l]]--;
            if (s2Freq[s2[l]] == 0) {
                s2Freq.erase(s2[l]);
            } 
            l++;
        }

        return false;
    }
};
