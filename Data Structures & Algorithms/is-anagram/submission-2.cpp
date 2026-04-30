class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> charCounts1;
        unordered_map<char, int> charCounts2;

        for (int i = 0; i < s.length(); i++) {
            charCounts1[s[i]]++;
            charCounts2[t[i]]++;
        }

        return charCounts1 == charCounts2;
    }
};
