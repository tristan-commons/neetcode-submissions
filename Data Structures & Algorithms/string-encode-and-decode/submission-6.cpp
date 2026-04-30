class Solution {
public:

    string encode(vector<string>& strs) {
        // put number of chars of each word before each word as delimiter
        // that way the algorithm can always know exactly where each delimieter is no matter the string contents
        // neet, code, love, you -> 4,neet4,code4,love3,you15,asdfjkl;asdfjkl

        string result;
        for (int i = 0; i < strs.size(); i++) {
            result += to_string(strs[i].length()) + ',';
            result += strs[i];
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int countStart = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ',') {
                continue;
            }

            string countString = s.substr(countStart, i - countStart);
            int count = stoi(countString);

            result.push_back(s.substr(i + 1, count));

            countStart = i + count + 1;
            i = countStart - 1;
        }

        return result;
    }
};
