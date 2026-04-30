class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        if (s.length !== t.length) {
            return false;
        }

        let sFreqMap = new Map();
        let tFreqMap = new Map();

        for (let i = 0; i < s.length; i++) {
            sFreqMap.set(s[i], (sFreqMap.get(s[i]) || 0) + 1);
            tFreqMap.set(t[i], (tFreqMap.get(t[i]) || 0) + 1);
        }

        if (sFreqMap.size !== tFreqMap.size) {
            return false;
        }

        for (let [key, sValue] of sFreqMap) {
            const tValue = tFreqMap.get(key);

            if (sValue !== tValue) {
                return false;
            }
        }


        return true;
    }
}
