class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cntFresh = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                if(grid[i][j] == 1) cntFresh++;
            }
        }
        int tm = 0,cnt = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(t,tm);
            q.pop();
            for(int i = 0;i < 4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                    q.push({{nrow,ncol},t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        if(cntFresh != cnt) return -1;
        return tm;
    }
};