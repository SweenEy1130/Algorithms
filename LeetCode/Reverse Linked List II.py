# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @param m, an integer
    # @param n, an integer
    # @return a ListNode
    def reverseBetween(self, head, m, n):
        if m == n:
            return head
        step = 0
        tnode = head
        prenode = ListNode(-1)
        prenode.next = head
        root = prenode
        start = root

        while tnode != None:
            step += 1
            if (step < m) or (step > n):
                if step == m - 1:
                    start = tnode
                prenode = tnode
                tnode = tnode.next
            else:
                postnode = tnode.next
                tnode.next = prenode
                if step == n and start != None:
                    start.next.next = postnode
                    start.next = tnode
                prenode = tnode
                tnode = postnode

        return root.next

if __name__ == '__main__':
    s = Solution()
    a = ListNode(1)
    b = ListNode(2)
    c = ListNode(3)
    d = ListNode(4)
    e = ListNode(5)
    a.next = b
    b.next = c
    c.next = d
    d.next = e
    head = s.reverseBetween(a, 1, 5)
    while head != None:
        print head.val, "->",
        head = head.next
    print None

