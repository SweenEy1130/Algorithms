# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
    # @return a list of Interval
    def insert(self, intervals, newInterval):
        ans = []
        # print newInterval.start,newInterval.end
        flag = 0
        for item in intervals:
            # print item.start, item.end
            if item.start < newInterval.start and item.end >= newInterval.start:
                newInterval.start = item.start
            if item.end > newInterval.end and item.start <= newInterval.end:
                newInterval.end = item.end
            if newInterval.start > item.end or newInterval.end < item.start:
                if flag = 0:
                    ans.append(newInterval)
                    flag = 1
                ans.append(item)
        return ans

if __name__ == '__main__':
    s = Solution()
    i1 = Interval(1,2)
    i2 = Interval(3,5)
    i3 = Interval(6,7)
    i4 = Interval(8,10)
    i5 = Interval(12,16)
    intervals = [i1, i2, i3, i4, i5]
    newInterval = Interval(4,9)
    # ans = s.insert(intervals, newInterval)
    ans = s.insert([Interval(1,4)], newInterval)
    for item in ans:
        print (item.start,item.end)