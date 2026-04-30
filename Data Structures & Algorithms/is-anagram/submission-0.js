class Solution {
    

    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        let sFreqMap = genFreqMap(s);
        let tFreqMap = genFreqMap(t);

        if (Object.entries(sFreqMap).length !== Object.entries(tFreqMap).length) {
            return false;
        }

        for (let char in sFreqMap) {
            console.log(char);
            if (sFreqMap[char] !== tFreqMap[char]) {
                return false;
            }
        }

        return true;

        function genFreqMap(s) {
            let freqMap = {};

            for (let char of s) {
                let charNum = freqMap[char] ?? 0;
                freqMap[char] = ++charNum;
            }

            return freqMap;
        }
    }
}
