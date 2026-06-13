class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        par = {')':'(', '}':'{', ']':'['}

        for c in s:
            if len(stack) > 0 and par.get(c, None) == stack[len(stack) - 1]:
                stack.pop()
            else:
                stack.append(c)
        
        return len(stack) == 0