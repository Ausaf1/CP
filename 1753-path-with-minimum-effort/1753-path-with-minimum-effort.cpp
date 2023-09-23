class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,0}});
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    dist[0][0] = 0;
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first,col = it.second.second;
        if(row == n-1 && col == m-1) return diff;
        for(int i = 0;i < 4;i++){
                int newr = row + dr[i];
                int newc = col + dc[i];
                if(newr >= 0 && newc >= 0 && newr < n && newc < m){
                    int newDiff = max(abs(heights[row][col] - heights[newr][newc]),diff);
                    if(newDiff < dist[newr][newc]){
                        pq.push({newDiff,{newr,newc}});
                        dist[newr][newc] = newDiff;
                }
            }
        }
    }
    return 0;
    }
};