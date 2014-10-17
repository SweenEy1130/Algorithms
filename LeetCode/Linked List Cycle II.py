# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a list node
    def detectCycle(self, head):
        tmp = head
        while tmp!= None:
            if tmp.val==-99999:
                return tmp
            tmp.val=-99999
            tmp=tmp.next
        return None

if __name__ == '__main__':
    root=ListNode(1)
    node1 = ListNode(1)
    root.next = node1
    node2 = ListNode(1)
    node1.next = node2
    node2.next = root
    s=Solution()
    print root
    print node1
    print node2
    print "Cycle Begins at ",s.detectCycle(root)