# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrderBottom(self, root):
        queue = []
        if root==None:
            return []
        queue.append([root,0])
        levelList = []
        level = 1
        tList = []
        while queue:
            tmp = queue.pop(0)
            if level == tmp[1]:
                levelList.append(tList)
                tList=[]
            tnode = tmp[0]
            level = tmp[1]+1
            tList.append(tnode.val)
            # print tList
            if tnode.left != None:
                queue.append([tnode.left, level])
            if tnode.right != None:
                queue.append([tnode.right, level])

        levelList.append(tList)

        return levelList[::-1]

if __name__ == '__main__':
    s = Solution()
    t3 = TreeNode(3)
    t9 = TreeNode(9)
    t20 = TreeNode(20)
    t3.left = t9
    t3.right = t20
    t15 = TreeNode(15)
    t7 = TreeNode(7)
    t20.left = t15
    t20.right = t7
    print s.levelOrderBottom(None)