# Definition for singly-linked list.
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution:
	# @return a ListNode
	def removeNthFromEnd(self, head, n):
		nth = ListNode(-1)
		nth.next = head
		root = nth
		counter = n
		while head != None:
			head = head.next
			if counter > 0:
				counter -= 1
			else:
				nth = nth.next
				
		nth.next = nth.next.next

		return root.next

if __name__ == '__main__':
	s = Solution()
	n = 1
	a = ListNode(1)
	b = ListNode(2)
	c = ListNode(3)
	d = ListNode(4)
	e = ListNode(5)
	a.next = b
	b.next = c
	c.next = d
	d.next = e
	head = s.removeNthFromEnd(a, n)
	while head != None:
		print head.val, "->",
		head = head.next
