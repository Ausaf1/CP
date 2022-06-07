class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        auto isSafe=[](int i,int j,int n,int m){
            return i>=0 && j>=0 && i<n && j<m;  
        };
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,1e5+1));
        if(grid[0][0] == 1) 
            dp[0][0]=1;
        else 
            dp[0][0]=0;
        vector<pair<int,int>> pr={{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int x=pr[k].first+i;
                int y=pr[k].second+j;
                if(isSafe(x,y,n,m)){
                    if(dp[x][y]>dp[i][j]+grid[i][j]){
                        dp[x][y]=dp[i][j]+grid[i][j];
                        q.push({x,y});
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};