class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isPalindrome(s) {
        let formatted = s.replaceAll(" ", "").toLowerCase().replace(/\W/g, '');

        let l = 0;
        let r = formatted.length - 1;

        while (l < r) {
            if (formatted.charAt(l) !== formatted.charAt(r)) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
}
