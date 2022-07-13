class Solution {
public:
    int m,n;
    bool isValid(int x,int y){
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    
    int dfs(vector<vector<int>>& grid,int r,int c,vector<vector<int>>& dp){
         if(r == m) return c;
        if(isValid(r,c)){
            if(grid[r][c]==1 && isValid(r,c+1) && grid[r][c+1]==1){
                if(dp[r+1][c+1]!=-2) return dp[r+1][c+1];
                else{
                    return dp[r+1][c+1] = dfs(grid,r+1,c+1,dp);
                }
            } 
            if(grid[r][c]==-1 && isValid(r,c-1) && grid[r][c-1]==-1){
                if(dp[r+1][c-1]!=-2) return dp[r+1][c-1];
                else{
                    return dp[r+1][c-1] = dfs(grid,r+1,c-1,dp);
                }
            } 
        }
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        m = grid.size(),n = grid[0].size();
        vector<vector<int>> dp(102,vector<int>(102,-2));
        vector<int> ans(n);
        for(int i = 0;i < n;i++)
            ans[i] = dfs(grid,0,i,dp);
        return ans;
    }
};