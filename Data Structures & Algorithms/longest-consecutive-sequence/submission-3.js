class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    longestConsecutive(nums) {
        if (nums.length === 1) {
            return 1;
        }

        nums = nums.sort((a, b) => a - b);

        let maxLen = 0;
        let curLen = 1;

        for (let i = 0; i < nums.length - 1; i++) {
            if (nums[i+1] === nums[i] + 1) {
                curLen++;
            } else if (nums[i+1] !== nums[i]){
                curLen = 1;
            }

            if (curLen > maxLen) {
                maxLen = curLen;
            }
        }

        return maxLen;
    }
}
