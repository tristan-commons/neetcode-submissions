class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.length() < 2) return s.length();

        int l = 0;
        unordered_map<char, int> freqMap;

        int maxLength = 1;
        int maxf = 0;
        for (int r = 0; r < s.length(); r++) {
            freqMap[s[r]]++;
            maxf = max(maxf, freqMap[s[r]]);

            while ((r - l + 1) - maxf > k) {
                freqMap[s[l]]--;
                l++;
            }
            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};
