class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        if(n == 1 && grid[0][0] == 0) return 1;
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0] = 1;
        grid[0][0] = -1;
        int dr[] = {-1,0,1,0,-1,1,1,-1};
        int dc[] = {0,1,0,-1,-1,1,-1,1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first,c = it.second.second;
            for(int i = 0;i < 8;i++){
                int newr = r + dr[i];
                int newc = c + dc[i];
                if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]){
                    dist[newr][newc] == dis + 1;
                    if(newr == n-1 && newc == n-1) return dis + 1;
                    q.push({dis + 1,{newr,newc}});
                    grid[newr][newc] = -1;
                }
            }
        }
        return -1;
    }
};