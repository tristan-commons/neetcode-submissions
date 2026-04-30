class Solution {
    /**
     * @param {string[]} strs
     * @returns {string}
     */
    encode(strs) {
        let result = "";

        for (let s of strs) {
            result += s.length + "*" + s;
        }

        return result;
    }

    /**
     * @param {string} str
     * @returns {string[]}
     */
    decode(str) {
        let results = [];
        let i = 0;

        while (i < str.length) {
            const nextSeparatorIdx = str.substring(i).indexOf("*") + i;
            const len = Number(str.substring(i, nextSeparatorIdx));
            i = nextSeparatorIdx + 1;

            let decodedStr = str.substring(i, i + len);
            results.push(decodedStr);

            i += len;
        }

        return results;
    }
}
