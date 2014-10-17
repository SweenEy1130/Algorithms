# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return nothing, do it in place
    def flatten(self, root):
        if root == None:
            return None
        head = TreeNode(-1)
        self.tranverse(root, head)
        self.reorder(root)
        return

    def tranverse(self, tnode, pre_node):
        if tnode != None:
            pre_node.left = tnode

        if tnode.left == None and tnode.right == None:
            return tnode

        pre_node = tnode
        if tnode.left != None:
            pre_node = self.tranverse(tnode.left, pre_node)

        if tnode.right != None:
            pre_node = self.tranverse(tnode.right, pre_node)

        return pre_node

    def reorder(self, root):
        head = root
        while head != None:
            head.right = head.left
            head.left = None
            head = head.right
        return

if __name__ == '__main__':
    s = Solution()
    t0 = TreeNode(0)
    t1 = TreeNode(1)
    t2 = TreeNode(2)
    t3 = TreeNode(3)
    t4 = TreeNode(4)
    t5 = TreeNode(5)
    t6 = TreeNode(6)
    t0.left = t1
    t0.right = t2
    t1.left = t3
    t1.right = t4
    t2.left = t5
    t2.right = t6
    s.flatten(t0)

    print t0.val, t0.right.val
    print t1.val, t1.right.val
    print t2.val, t2.right.val
    print t3.val, t3.right.val
    print t4.val, t4.right.val
    print t5.val, t5.right.val
    print t6.val, t6.right
