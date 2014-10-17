class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        lena, lenb = len(a), len(b)
        c = ""
        carry = 0
        while lena > 0 or lenb > 0:
            aa,bb = 0,0
            if lena > 0:
                aa = a[lena-1]
                lena -= 1
            if lenb > 0:
                bb = b[lenb-1]
                lenb -= 1
            s = (carry + int(aa)+int(bb))
            c = str(s % 2) + c
            carry = s / 2
        if carry != 0:
            c = str(carry)+c
        return c

if __name__ == '__main__':
    s = Solution()
    a = "1"
    b = "001"
    print s.addBinary(a,b)