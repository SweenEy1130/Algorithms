class Solution:
	# @return a boolean
	def isValid(self, s):
		stack = []

		for i in range(0, len(s)):
			ch = s[i]
			if ch == "(" or ch == "[" or ch == "{":
				stack.append(ch)
			elif ch == ")":
				if not stack or stack[-1] != "(":
					return False
				else:
					stack.pop()
			elif ch == "]":
				if not stack or stack[-1] != "[":
					return False
				else:
					stack.pop()				
			elif ch == "}":
				if not stack or stack[-1] != "{":
					return False
				else:
					stack.pop()
		if stack:
			return False
		return True

if __name__ == '__main__':
	s = Solution()
	st = '{}'
	print s.isValid(st)