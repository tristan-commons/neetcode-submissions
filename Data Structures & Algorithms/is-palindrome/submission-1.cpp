class Solution {
public:
    bool isPalindrome(string s) {
        string str = s;
        regex r("[^a-zA-Z0-9]");
        string filtered = regex_replace(str, r, "");
        int left = 0;
        int right = filtered.length() - 1;

        while (left < right) {
            char leftChar = tolower(filtered[left]);
            char rightChar = tolower(filtered[right]);
            cout << "Left: " << leftChar << ", Right: " << rightChar << "\n";
            if (leftChar != rightChar) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
