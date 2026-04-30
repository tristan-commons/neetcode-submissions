class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs) {
        let groups = new Map();

        for (let str of strs) {
            const freqMap = this.genFreqMap(str);
            const freqMapString = JSON.stringify(Array.from(freqMap.entries()));

            if (groups.has(freqMapString)) {
                groups.get(freqMapString).push(str);
                continue;
            }

            groups.set(freqMapString, [str]);
        }

        let arr = []
        for (let [key, value] of groups) {
            arr.push(value);
        }
        return arr;
    }

    genFreqMap(str) {
        let map = new Map();

        for (let char of str) {
            map.set(char, (map.get(char) || 0) + 1);
        };

        return new Map([...map.entries()].sort());
    }
}
