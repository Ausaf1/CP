class Solution {
public:
    int helper(int amount,int n,vector<int>& coins,vector<vector<int>>& dp){
        if(n<=0) return INT_MAX-1;
        if(amount == 0)
            return 0;
        if(dp[amount][n]!=-1)
            return dp[amount][n];
        if(coins[n-1]<=amount)
            return dp[amount][n] = min(1+helper(amount-coins[n-1],n,coins,dp),helper(amount,n-1,coins,dp));
        else
            return dp[amount][n] = helper(amount,n-1,coins,dp);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n+1,-1));
        int minimum = helper(amount,n,coins,dp);
        if(minimum == INT_MAX-1)
            return -1;
        else
            return minimum;
    }
};