# Definition for singly-linked list.
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution:
	# @return a ListNode
	def addTwoNumbers(self, l1, l2):
		t1 = l1
		t2 = l2
		carry = 0
		head = tnode = ListNode(-1)
		while t1!=None or t2!=None:
			val = carry
			if t1!= None:
				val = val + t1.val
				t1 = t1.next
			if t2!=None:
				val = val + t2.val
				t2 = t2.next
			carry = val // 10
			tnode.next = ListNode(val % 10)
			tnode = tnode.next
			if t1 == None and t2 == None and carry != 0:
				tnode.next = ListNode(carry)
				tnode = tnode.next

		return head.next

if __name__ == '__main__':
	s = Solution()
	l1 = ListNode(2)
	l2 = ListNode(9)
	head = s.addTwoNumbers(l1, l2)
	while head != None:
		print head.val, "->",
		head = head.next
