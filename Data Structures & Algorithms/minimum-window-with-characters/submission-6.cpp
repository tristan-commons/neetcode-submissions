class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tFreq;
        unordered_map<char,int> window;
        unordered_map<char, int> overflow;

        for (const auto& letter : t) {
            tFreq[letter]++;
        }

        int minStart = 0;
        int minLen = INT_MAX;
        int l = 0;
        int r = 0;
        while (r < s.length() && l <= r) {
            int tCount = tFreq.count(s[r]) ? tFreq[s[r]] : 0;
            if (tCount > 0) {
                if (window[s[r]] == tCount) {
                    overflow[s[r]]++;
                } else {
                    window[s[r]]++;
                }
            }

            while (tFreq == window) {
                int len = r - l + 1;
                if (len < minLen) {
                    minStart = l;
                    minLen = len;
                }
                if (tFreq.count(s[l]) > 0) {
                    if (overflow[s[l]] > 0) {
                        overflow[s[l]]--;
                    } else {
                        window[s[l]]--;
                    }
                }
                l++;
            }

            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};