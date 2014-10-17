# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def isBalanced(self, root):
        if root==None:
            return True
        self.flag = True
        self.isDepth(root)

        return self.flag

    def isDepth(self, tnode):
        if self.flag==0:
            return 0
        if tnode.left == None and tnode.right == None:
            return 1
        l = 0
        r = 0
        if tnode.left != None:
            l = self.isDepth(tnode.left)
        if tnode.right != None:
            r = self.isDepth(tnode.right)

        if abs(l-r)>1:
            self.flag = False

        # print (tnode.val, max(l,r) + 1)
        return max(l,r) + 1
        
if __name__ == '__main__':
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
    s = Solution()
    print s.isBalanced(t0)
