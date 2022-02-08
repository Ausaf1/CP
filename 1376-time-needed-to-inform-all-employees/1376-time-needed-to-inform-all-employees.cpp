class Solution {
public:
    int dfs(int i,vector<int>& manager,vector<int>& informTime,vector<int>& dp){
        if(manager[i] == -1)
            return 0;
        else if(dp[manager[i]] != -1)
            return dp[manager[i]];
        return dp[manager[i]] = informTime[manager[i]] + dfs(manager[i],manager,informTime,dp); 
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = INT_MIN;
        vector<int> dp(n,-1);
        for(int i = 0;i < n;i++){
            res = max(res,dfs(i,manager,informTime,dp));
        }
        return res;
    }
};