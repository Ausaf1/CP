class Solution {
public:
     void fun(int i,int j,int prev,vector<vector<int>>&heights,vector<vector<int>>&dp) {
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) {
            return;
        }
        if(dp[i][j] == 1) {
            return;
        }
        if(heights[i][j] < prev) {
            return;
        }
        dp[i][j] = 1;
        fun(i + 1,j,heights[i][j],heights,dp);
        fun(i - 1,j,heights[i][j],heights,dp);
        fun(i,j + 1,heights[i][j],heights,dp);
        fun(i,j - 1,heights[i][j],heights,dp);

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>&heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>ans;
        vector<vector<int>>pacific(m,vector<int>(n,0));
        vector<vector<int>>atlantic(m,vector<int>(n,0));

        for(int col = 0; col < n; col++) {
            fun(0,col,INT_MIN,heights,pacific);
            fun(m - 1,col,INT_MIN,heights,atlantic);
        }
        for(int row = 0; row < m; row++) {
            fun(row,0,INT_MIN,heights,pacific);        
            fun(row,n - 1,INT_MIN,heights,atlantic);                    
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};