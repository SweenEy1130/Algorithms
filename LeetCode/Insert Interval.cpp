/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ans;
        int n = intervals.size(), k = 0;
        while (k < n){
            if (intervals[k].end < newInterval.start){
                ans.push_back(intervals[k]);
                k++;
            }else{
                break;
            }
        }
        while (k < n && !(intervals[k].end < newInterval.start || intervals[k].start > newInterval.end)){
            newInterval.start = min(intervals[k].start , newInterval.start);
            newInterval.end = max(intervals[k].end , newInterval.end);
            k++;
        }
        ans.push_back(newInterval);
        while (k < n){
            ans.push_back(intervals[k]);
            k++;
        }
        return ans;
    }
};