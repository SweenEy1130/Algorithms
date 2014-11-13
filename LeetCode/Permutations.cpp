class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Add an empty vector as the base case (empty input)
        vector<vector<int> > permutations(1, vector<int>());
        // Algrithm description:
        //  Insert the current number in different spaces of previous permutations
        for (vector<int>::size_type index = 0; index != num.size(); ++index)
        {
            vector<vector<int> > subPermutations(permutations);
            permutations.clear();
            for (vector<vector<int> >::size_type i = 0; i != subPermutations.size(); ++i)
            {
                for (int offset = 0; offset != subPermutations[i].size()+1; ++offset)
                {
                    vector<int> temp(subPermutations[i]);
                    temp.insert(temp.begin() + offset, num[index]);
                    permutations.push_back(temp);
                }
            }
        }
        return permutations;
    }
};