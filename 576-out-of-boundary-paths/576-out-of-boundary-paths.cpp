class Solution {
public:
    #define ll long long
    ll mod = 1e9 + 7;
    int dp[51][51][51];
    int dfs(int m,int n,int i,int j,int moves){
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 1;
        if(moves <= 0)
            return 0;
        if(dp[i][j][moves] != -1)
            return dp[i][j][moves];
        int left = dfs(m,n,i,j-1,moves-1);
        int right = dfs(m,n,i,j+1,moves-1);
        int up = dfs(m,n,i-1,j,moves-1);
        int down = dfs(m,n,i+1,j,moves-1);
        return dp[i][j][moves] = (left % mod + right % mod + up % mod + down %  mod) % mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return dfs(m,n,startRow,startColumn,maxMove);
    }
};