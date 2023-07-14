class Solution {
private:
    int f(int idx,vector<int> &coins,int amt,vector<vector<int>> &dp){
        if(idx < 0) return 1e8;
        if(amt == 0) return 0;
        if(dp[idx][amt] != -1) return dp[idx][amt];
        int take = 0,notTake = 0;
        if(amt >= coins[idx]) take = min(1 + f(idx,coins,amt - coins[idx],dp),f(idx - 1,coins,amt,dp));
        else notTake = f(idx - 1,coins,amt,dp);
        return dp[idx][amt] = take + notTake;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount + 1,-1));
        int mn = f(n-1,coins,amount,dp);
        if(mn == 1e8) return -1;
        return mn;
    }
};