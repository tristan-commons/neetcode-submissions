# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        tree_stack = []
        tree_stack.append(root)

        while len(tree_stack) > 0:
            cur = tree_stack[-1]
            tree_stack.pop()

            temp_left = cur.left
            cur.left = cur.right
            cur.right = temp_left

            if cur.left:
                tree_stack.append(cur.left)
            if cur.right:
                tree_stack.append(cur.right)
        
        return root


            