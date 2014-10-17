# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.total = 0

    # @param root, a tree node
    # @return an integer
    def sumNumbers(self, root):
        if root==None:
            return 0
        self.tranverse(root, 0)
        return self.total

    def tranverse(self, tNode, val):
        # print (tNode.val, val)
        val = val*10+tNode.val
        if tNode!=None:
            if tNode.left != None:
                self.tranverse(tNode.left, val)
            if tNode.right != None:
                self.tranverse(tNode.right, val)

            # leave node
            if tNode.right == None and tNode.left == None:
                # print "Leave node:", (tNode.val,val)
                self.total += val

if __name__ == '__main__':
    s=Solution()
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.right = TreeNode(3)
    print s.sumNumbers(None)