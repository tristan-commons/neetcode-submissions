class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2) return s.length();

        int l = 0;
        int r = 1;
        unordered_map<char, int> freqMap;
        freqMap[s[l]]++;

        int maxLength = 1;
        int duplicates = 0;
        while (r < s.length()) {
            freqMap[s[r]]++;

            if (freqMap[s[r]] > 1) {
                duplicates++;
            }

            if (duplicates > 0) {
                freqMap[s[l]]--;
                if (freqMap[s[l]] > 0) duplicates--;
                l++;
                r++;
            } else {
                maxLength = max(maxLength, r - l + 1);
                r++; 
            }
        }

        return maxLength;
    }
};
