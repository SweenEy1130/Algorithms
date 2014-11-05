class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int l = gas.size();
        int total = 0, summ = 0, index = 0;
        for (int i = 0; i < l; ++i)
        {
            summ += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (summ < 0)
            {
                index = (i+1) % l;
                summ = 0;
            }
        }

        if (total >= 0)
            return index;
        else
            return -1;
    }
};