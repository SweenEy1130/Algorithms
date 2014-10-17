class Solution:
    # @param gas, a list of integers
    # @param cost, a list of integers
    # @return an integer
    def canCompleteCircuit(self, gas, cost):
        total = 0
        summ = 0
        index = 0
        size = len(gas)
        for i in range(0, size):
            summ += gas[i] - cost[i]
            total += gas[i] - cost[i]
            if summ < 0:
                index = (i+1) % size
                summ = 0
        if total >=0:
            return index
        else:
            return -1

if __name__ == '__main__':
    s = Solution()
    gas = [3,2,1,1]
    cost = [1,3,1,2]
    print s.canCompleteCircuit(gas,cost)