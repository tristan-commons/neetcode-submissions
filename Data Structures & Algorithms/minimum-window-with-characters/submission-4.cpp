class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tFreq;
        unordered_map<char,int> window;
        unordered_map<char, int> overflow;

        for (const auto& letter : t) {
            tFreq[letter]++;
            cout << "tFreq[" << letter << "] = " << tFreq[letter] << ", ";
        }
        cout << "\n";

        string minStr = "";
        int l = 0;
        int r = 0;
        while (r < s.length() && l <= r) {
            cout << "l: " << to_string(l) << " r: " << to_string(r) << ", ";
            cout << "Char: " << s[r] << ", ";

            int tCount = tFreq.count(s[r]) ? tFreq[s[r]] : 0;
            if (tCount > 0) {
                if (window[s[r]] == tCount) {
                    overflow[s[r]]++;
                } else {
                    window[s[r]]++;
                }
                
                cout << "window[" << s[r] << "] = " << window[s[r]] << ", ";
            }

            // While every character in t is within the window
            while (tFreq == window) {
                int minLength = minStr == "" ? s.length()+1 : minStr.length();
                if (r - l + 1 < minLength) {
                    minStr = s.substr(l, r - l + 1);
                    cout << "New MinStr: " << minStr << ", ";
                }

                if (tFreq.count(s[l]) > 0) {
                    
                    if (overflow[s[l]] > 0) {
                        overflow[s[l]]--;
                    } else {
                        window[s[l]]--;
                    }

                    cout << "window[" << s[l] << "] = " << window[s[l]] << ", ";
                }
                
                l++;
            }

            r++;
            cout << "\n";
        }

        return minStr;

    }
};
