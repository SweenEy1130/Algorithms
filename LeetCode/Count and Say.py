class Solution:
    # @return a string
    def countAndSay(self, n):
        st = "1"
        for i in range(1,n):
            ans = ""
            cnt = 1
            for j in range(len(st)):
                if j+1 < len(st) and st[j] == st[j+1]:
                    cnt += 1
                else:
                    ans = ans+str(cnt)+st[j]
                    cnt = 1
            # print st
            st = ans
        return st

if __name__ == '__main__':
    s = Solution()
    print s.countAndSay(6)