class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum(self, candidates, target):
        f = [[0 for col in range(target+1)] for row in range(len(candidates))]
        for j in range(len(candidates)):
            f[j][0] = []
        for i in range(0, len(candidates)):
            for j in range(target+1):
                if f[i][j-candidates[i]] != 0:
                    if f[i][j]==0:
                        f[i][j] = []
                    if f[i][j-candidates[i]] == []:
                        f[i][j] = [[candidates[i]]]
                    for item in f[i][j-candidates[i]]:
                        new_item = item[:]
                        new_item.append(candidates[i])
                        f[i][j].append(new_item)

                if i-1 >= 0 and f[i-1][j] != 0:
                    if f[i][j]==0:
                        f[i][j] = []
                    for item in f[i-1][j]:
                        f[i][j].append(item)

        return f[len(candidates)-1][target]

if __name__ == '__main__':
    s = Solution()
    candidates = [2,3,6,7]
    target = 7
    print s.combinationSum(candidates, target)