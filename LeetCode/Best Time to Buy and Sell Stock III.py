class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        l = len(prices)
        if l == 0:
            return 0
        scanLeft = [0] * l
        scanLeft[0] = 0
        minPrice = prices[0]
        for i in range(1, l):
            scanLeft[i] = max(scanLeft[i-1], prices[i] - minPrice)
            if prices[i] < minPrice:
                minPrice = prices[i]

        scanRight = [0] * l
        maxPrice = prices[l-1]
        scanRight[l-1] = 0
        for i in range(l-2, -1, -1):
            scanRight[i] = max(scanRight[i+1], maxPrice - prices[i])
            if prices[i] > maxPrice:
                maxPrice = prices[i]

        maxTwoProfits=0
        for i in range(l):
            if scanRight[i]+scanLeft[i] > maxTwoProfits:
                maxTwoProfits = scanRight[i]+scanLeft[i]

        return maxTwoProfits


if __name__ == '__main__':
    s=Solution()
    print s.maxProfit([5,1,12,2,3,5,13])
    print s.maxProfit([])


