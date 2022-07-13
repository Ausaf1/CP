class Solution {
public:
    int helper(int n,vector<int> &cuts,int start,int end,vector<vector<int>> &dp){
        if(abs(start-end) <= 1)
            return 0;
        if(dp[start][end] != -1)
            return dp[start][end];
        int min_cost = INT_MAX;
        for(int i = start + 1;i <= end - 1;i++){
            int curr_cost = cuts[end] - cuts[start] + helper(n,cuts,i,end,dp) + helper(n,cuts,start,i,dp);
            if(curr_cost < min_cost || min_cost == INT_MAX)
                min_cost = curr_cost;
        }
        return dp[start][end] = min_cost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int m = cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return helper(n,cuts,0,m-1,dp);
    }
};