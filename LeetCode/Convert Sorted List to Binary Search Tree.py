# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a list node
    # @return a tree node
    def sortedListToBST(self, head):
        if head == None:
            return None
        l, tmp = 0, head
        while tmp != None:
            l += 1
            tmp = tmp.next
        treelist = self.sortedListToBST3(head, l)
        return treelist[0]

    def sortedListToBST3(self, head, l):
        if l == 1:
            return [TreeNode(head.val), head.next]

        left = self.sortedListToBST3(head, l/2)
        parent = TreeNode(left[1].val)
        parent.left = left[0]

        if (l-1)/2:
            right = self.sortedListToBST3(left[1].next, (l-1)/2)
            parent.right = right[0]
            return [parent, right[1]]
        else:
            return [parent, left[1].next]

if __name__ == '__main__':
    s = Solution()
    a = ListNode(1)
    b = ListNode(2)
    c = ListNode(3)
    d = ListNode(4)
    e = ListNode(5)
    f = ListNode(6)
    a.next = b
    b.next = c
    c.next = d
    d.next = e
    e.next = f
    head = s.sortedListToBST(a)
    queue = [head]
    while queue:
        tmp = queue.pop()
        print tmp.val, "->",

        if tmp.left != None:
            print tmp.left.val, ":",
            queue.append(tmp.left)
        if tmp.right != None:
            print tmp.right.val,
            queue.append(tmp.right)
        print

