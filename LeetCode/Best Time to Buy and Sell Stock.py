class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        f = [0] * len(prices)
        mmin = 9999999
        for i in range(len(prices)):
            f[i] = prices[i] - mmin
            if prices[i] < mmin:
                mmin = prices[i]
        
        maxProfit = 0
        for i in range(len(prices)):
            if f[i] > maxProfit:
                maxProfit = f[i]
        return maxProfit

if __name__ == '__main__':
    s=Solution()
    print s.maxProfit([5,1,12,2,3,5,13])
    print s.maxProfit([])
    print s.maxProfit([5])

