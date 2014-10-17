class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        n = len(prices)
        ans = 0
        for i in range(1,n):
        	if prices[i] > prices[i-1]:
        		ans += prices[i] - prices[i-1]
        return ans

if __name__ == '__main__':
	s = Solution()
	prices = [0,1,10,3,4,5]
	print s.maxProfit(prices)