class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size();
        int ans = 1,lastpoint = points[0][1];
        for(int i = 0;i < n;i++){
            if(points[i][0] > lastpoint){
                ans++;
                lastpoint = points[i][1];
            }
            lastpoint = min(lastpoint,points[i][1]);
        }
        return ans;
    }
};