class Solution {
public:
    bool isValid(string s) {
        stack<char> starts;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            bool valid = true;
            if (c == '(' || c == '[' || c == '{') {
                starts.push(c);
                continue;
            
            }
            if (starts.empty()) return false;

            char left = starts.top();
            starts.pop();
            switch (c) {
                case ')':
                    valid = left == '(';
                    break;
                case ']':
                    valid = left == '[';
                    break;
                case '}':
                    valid = left == '{';
                    break;
            }

            if (!valid) return false;
        }

        return starts.empty();
    }
};
