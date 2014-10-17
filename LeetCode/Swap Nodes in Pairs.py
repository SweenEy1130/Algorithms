# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
	# @param a ListNode
	# @return a ListNode
	def swapPairs(self, head):
		if head == None or head.next == None:
			return head
		elif head.next != None:
			ans = head.next

		tNode=head
		pNode=None
		rNode=ListNode(-1)

		while tNode and tNode.next:
			pNode=tNode
			tNode=tNode.next

			rNode.next=tNode
			pNode.next=tNode.next
			tNode.next=pNode

			tNode=pNode.next
			rNode=pNode

		return ans

	def Print(self,head):
		while head!=None:
			print head.val,"->",
			head=head.next
		print "None"

if __name__ == '__main__':
	s = Solution()
	p0 = ListNode(0)
	p1 = ListNode(1)
	p0.next = p1
	p2 = ListNode(2)
	p1.next = p2
	p3 = ListNode(3)
	p2.next = p3
	ans = s.swapPairs(p0)
	s.Print(ans)