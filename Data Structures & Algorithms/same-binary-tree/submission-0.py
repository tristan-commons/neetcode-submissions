# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        tree_p = []
        tree_q = []

        tree_p.append(p)
        tree_q.append(q)

        while len(tree_p) > 0 and len(tree_q) > 0:
            cur_p = tree_p[-1]
            tree_p.pop()
            cur_q = tree_q[-1]
            tree_q.pop()

            p_n = not cur_p
            q_n = not cur_q

            if p_n != q_n:
                return False
            if not (p_n or q_n) and cur_q.val != cur_p.val:
                return False
            
            if not p_n:
                tree_p.append(cur_p.left)
                tree_p.append(cur_p.right)
            
            if not q_n:
                tree_q.append(cur_q.left)
                tree_q.append(cur_q.right)
        
        if len(tree_p) != 0 or len(tree_q) !=0:
            return False
        
        return True