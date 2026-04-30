class Solution {
    /**
     * @param {number[]} numbers
     * @param {number} target
     * @return {number[]}
     */
    twoSum(numbers, target) {
        let numMap = new Map();

        for (let i = 0; i < numbers.length; i++) {
            numMap.set(numbers[i], i);
        }

        for (const [num, idx] of numMap) {
            let comp = target - num;
            if (numMap.has(comp)) {
                return [
                    idx + 1,
                    numMap.get(comp) + 1
                ]
            }
        }

        return [];
    }
}
