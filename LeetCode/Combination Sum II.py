class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum2(self, candidates, target):
        candidates.sort()
        solution =[]
        self.combinationSum2Rec(candidates, target, 0, 0, [], solution)
        return solution

    def combinationSum2Rec(self, candidates, target, index, sum, tempList, solution):
        if sum == target:
            solution.append(list(tempList))
            return
        for i in range(index, len(candidates)):
            if (i==index or candidates[i-1]!=candidates[i]) and sum+candidates[i]<=target:
                tempList.append(candidates[i])
                self.combinationSum2Rec(candidates, target, i+1, sum+candidates[i], tempList, solution)
                tempList.pop()

if __name__ == '__main__':
    s = Solution()
    candidates = [2,3,6,7]
    target = 7
    print s.combinationSum(candidates, target)