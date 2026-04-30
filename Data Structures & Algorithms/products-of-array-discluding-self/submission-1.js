class Solution {
    /**
     * @param {number[]} nums
     * @return {number[]}
     */
    productExceptSelf(nums) {
        let result = [];
        let leftProducts = [];
        let rightProducts = [];
        let leftProduct = 1;
        let rightProduct = 1;
        
        for (let i = 0; i < nums.length; i++) {
            leftProducts[i] = leftProduct;
            leftProduct *= nums[i];
        }

        for (let i = nums.length - 1; i >= 0; i--) {
            rightProducts[i] = rightProduct;
            rightProduct *= nums[i];
        }
        
        for (let i = 0; i < nums.length; i++) {
            result[i] = leftProducts[i] * rightProducts[i];
        }

        return result;
    }
}
