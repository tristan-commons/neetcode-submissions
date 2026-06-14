# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        tree = []
        tree.append((root, 1))

        max_depth = 1

        while len(tree) > 0:
            cur_pair = tree[-1]
            tree.pop()

            cur = cur_pair[0]
            depth = cur_pair[1]

            max_depth = max(depth, max_depth)

            if cur.left:
                tree.append((cur.left, depth + 1))
            if cur.right:
                tree.append((cur.right, depth + 1))
        
        return max_depth