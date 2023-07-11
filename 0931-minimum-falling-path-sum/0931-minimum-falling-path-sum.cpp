class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0; i < n; i++) dp[0][i] = matrix[0][i];
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
            int up = matrix[i][j] + dp[i - 1][j];
            int ld = 0;
            if(j - 1 >= 0)  ld = matrix[i][j] + dp[i - 1][j - 1];
            else  ld += INT_MAX;
            int rd = 0;
            if(j + 1 < n) rd = matrix[i][j] + dp[i - 1][j + 1];
            else  rd += INT_MAX;
            dp[i][j] = min(up, min(ld, rd));           
            }
        }
        int mnPath = 1e8;
        for(int i = 0;i < n;i++) mnPath = min(mnPath,dp[m-1][i]);
        return mnPath;
    }
};