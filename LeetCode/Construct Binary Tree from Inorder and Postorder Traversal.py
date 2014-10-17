# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
	# @param inorder, a list of integers
	# @param postorder, a list of integers
	# @return a tree node
	def buildTree(self, inorder, postorder):
		if len(postorder) == 0:
			return None

		head = self.convert(inorder, postorder, 0, len(postorder) - 1, len(postorder) - 1)

		return head

	def convert(self, inorder, postorder, st_idx, end_idx, root_idx):
		if st_idx > end_idx:
			return None 
		tnode = TreeNode(postorder[root_idx])
		mid = st_idx
		for i in xrange(st_idx, end_idx + 1):
			if inorder[i] == tnode.val:
				mid = i
				break

		tnode.left = self.convert(inorder, postorder, st_idx, mid - 1, root_idx - 1 - end_idx + mid)
		tnode.right = self.convert(inorder, postorder, mid + 1, end_idx, root_idx - 1)

		return tnode

if __name__ == '__main__':
	s = Solution()
	# inorder = [1,3,2]
	# postorder = [3,2,1]
	inorder = [4, 2, 5, 1, 3, 6]
	postorder = [4, 5, 2, 6, 3, 1]
	head = s.buildTree(inorder, postorder)
	print head.left.val
	print head.right.val
	print head.left.left.val
	print head.left.right.val
	print head.right.left.val
