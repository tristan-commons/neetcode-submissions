class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums, k) {
       let fMap = new Map();

       for (let num of nums) {
        fMap.set(num, (fMap.get(num) || 0) + 1);
       }
       let result = [];

       fMap = new Map([...fMap.entries()].sort((a,b) => b[1] - a[1]));
       let keys = fMap.keys();
       for (let i = 0; i < k; i++) {
        result.push(keys.next().value);
       }
       return result;
    }
}
