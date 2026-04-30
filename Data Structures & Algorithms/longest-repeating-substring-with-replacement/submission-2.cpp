class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.length() < 2) return s.length();

        int l = 0;
        unordered_map<char, int> freqMap;
        freqMap[s[l]]++;

        int maxLength = 1;
        int majChar = s[l];
        for (int r = 1; r < s.length(); r++) {
            freqMap[s[r]]++;
            
            if (freqMap[s[r]] > freqMap[majChar]) {
                majChar = s[r];
            }

            while ((r - l + 1) - freqMap[majChar] > k) {
                freqMap[s[l]]--;
                l++;
                if (freqMap[s[l]] > freqMap[majChar]) majChar = s[l];
                if (freqMap[s[r]] > freqMap[majChar]) majChar = s[r];
            }
            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};
