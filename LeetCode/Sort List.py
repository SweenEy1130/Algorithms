# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def sortList(self, head):
        if head==None or head.next==None:
            return head
        tmp = head
        while tmp.next != None:
            tmp = tmp.next
        tail = tmp
        head,tail = self.qsort(head, tail)
        return head

    def qsort(self, start, end):
        if start == None or end == None or start == end:
            return start,end
        mid = start
        tmp = start
        pre = mid
        flag = 0
        while flag == 0:
            # print tmp.val,
            tmp = tmp.next
            if tmp == end:
                flag = 1
            # print flag
            if tmp != None and tmp.val >= mid.val:
                pre = tmp
                continue
            pre.next = tmp.next
            tmp.next = start
            start = tmp
            tmp = pre
            if flag == 1:
                break
        end = tmp
        # print (start.val, end.val, mid.val)
        # self.printList(start,end)
        s,e = self.qsort(start, mid)
        s1,e1 = self.qsort(mid.next, end)
        e.next = s1

        return s,e1

    def printList(self, head, tail):
        while head != tail:
            print head.val,"->",
            head=head.next
        if tail!=None:
            print tail.val
        else:
            print "None"

if __name__ == '__main__':
    s = Solution()
    node0 = ListNode(2)
    node1 = ListNode(1)
    # node2 = ListNode(3)
    # node3 = ListNode(6)
    # node4 = ListNode(0)
    node0.next = node1
    # node1.next = node2
    # node2.next = node3
    # node3.next = node4

    head = s.sortList(node0)
    s.printList(head, None)


class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def sortList(self, head):
        length = 0
        curr = head;
        while curr != None:
            length += 1
            curr = curr.next
        return self.mergeSort(head, length)
     
    def mergeSort(self, head, length):
        # base case
        if length == 1 or length == 0: return head
         
        # sort the two halves of the list
        prev = curr = head
        for i in xrange(length / 2): curr = curr.next
        for i in xrange(length / 2 - 1): prev = prev.next
        prev.next = None
        head1 = self.mergeSort(head, length / 2)
        head2 = self.mergeSort(curr, length - length / 2)
         
        # merge sorted halves into one
        if head1.val <= head2.val: 
            curr = newHead = ListNode(head1.val)
            head1 = head1.next
        else: 
            curr = newHead = ListNode(head2.val)
            head2 = head2.next
        while head1 and head2:
            if head1.val <= head2.val:
                curr.next = ListNode(head1.val)
                head1 = head1.next
            else:
                curr.next = ListNode(head2.val)
                head2 = head2.next
            curr = curr.next
        while head1:
            curr.next = ListNode(head1.val)
            head1 = head1.next
            curr = curr.next
        while head2:
            curr.next = ListNode(head2.val)
            head2 = head2.next
            curr = curr.next
        return newHead