class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 1;i <=m;i++){
            for(int j = 1; j<=n; j++){
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+1;
                    maxArea = max(maxArea,dp[i][j]);
                }
            }
        }
        return maxArea*maxArea;
    }
};