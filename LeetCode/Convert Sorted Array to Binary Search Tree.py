# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param num, a list of integers
    # @return a tree node
    def sortedArrayToBST(self, num):
        return self.addNode(0, len(num)-1, num)

    def addNode(self, start, end, tlist):
        if start > end:
            return None
        mid = (start + end) / 2
        mNode = TreeNode(tlist[mid])
        mNode.left = self.addNode(start, mid-1, tlist)
        mNode.right = self.addNode(mid+1, end, tlist)
        return mNode

    def printNode(self, tnode):
        queue = []
        head = 0
        tail = 0
        queue.append(tnode)
        while queue:
            tmp = queue.pop(0)
            if tmp != None:
                print tmp.val," ",
            else:
                print "#",' ',
                continue
            if tmp.left == None and tmp.right == None:
                continue
            if tmp.left != None:
                queue.append(tmp.left)
            else:
                queue.append(None)

            if tmp.right != None:
                queue.append(tmp.right)
            else:
                queue.append(None)

if __name__ == '__main__':
    s = Solution()
    num = [0,1,2,3,4,5,6]
    num = [0,1]
    node = s.sortedArrayToBST(num)
    s.printNode(node)
