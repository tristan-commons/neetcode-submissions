class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    longestConsecutive(nums) {
        const numSet = new Set(nums);
        let maxLen = 0;

        for (const n of numSet) {
            if (!numSet.has(n - 1)) {
                let curLen = 1;
                while (numSet.has(n + curLen)) {
                    curLen++;
                }
                maxLen = Math.max(curLen, maxLen);
            }
        }

        return maxLen
    }
}
