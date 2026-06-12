class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = []
        product = 1

        num_zeroes = 0

        for n in nums:
            if n == 0:
                num_zeroes += 1
                continue
            product *= n
        
        if num_zeroes > 1:
            return [0 for n in nums]
        
        for n in nums:
            if n == 0:
                res.append(product)
            elif num_zeroes > 0:
                res.append(0)
            else:
                res.append(int(product/n))
        
        return res