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
        queue = [root]
        index_num = 0
        power = 2
        while queue:
            # print len(queue)
            index_num += 1
            tNode = queue.pop(0)
            # print (index_num, power, tNode.val)
            if index_num == power - 1:
                power *= 2
                tNode.next = None
            else:
                tNode.next = queue[0]

            if tNode.left != None and tNode.right != None:
                queue.append(tNode.left)
                queue.append(tNode.right)

        return
        
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
    s.connect(t0)
    print (t0, t0.next)
    print (t1, t1.next.val)
    print (t2, t2.next)
    print (t3, t3.next.val)
    print (t4, t4.next.val)
    print (t5, t5.next.val)
    print (t6, t6.next)

