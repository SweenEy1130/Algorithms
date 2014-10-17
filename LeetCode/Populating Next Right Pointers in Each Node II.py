# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None

class Solution:
    # @param root, a tree node
    # @return nothing
    def connect(self, root):
        if root == None:
            return
        queue = [(root, 0)]
        while queue:
            tNode, level = queue.pop(0)

            if tNode.left != None:
                queue.append((tNode.left, level+1))
            if tNode.right != None:
                queue.append((tNode.right, level+1))

            if not queue:
                tNode.next = None
            elif level != queue[0][1]:
                tNode.next = None
            else:
                tNode.next = queue[0][0]

        return
        
if __name__ == '__main__':
    t0 = TreeNode(1)
    t1 = TreeNode(2)
    t2 = TreeNode(3)
    t3 = TreeNode(4)
    t4 = TreeNode(5)
    t5 = TreeNode(7)
    t0.left = t1
    t0.right = t2
    t1.left = t3
    t1.right = t4
    t2.left = t5
    s = Solution()
    s.connect(t0)
    print (t0, t0.next)
    print (t1, t1.next.val)
    print (t2, t2.next)
    print (t3, t3.next.val)
    print (t4, t4.next.val)
    print (t5, t5.next)

