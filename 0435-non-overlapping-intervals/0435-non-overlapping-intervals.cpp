class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int ans = 0;
        int endTime = -60000;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] < endTime) {
                ans++;
            } else {
                endTime = intervals[i][1];
            }
        }
        
        return ans;
    }
};