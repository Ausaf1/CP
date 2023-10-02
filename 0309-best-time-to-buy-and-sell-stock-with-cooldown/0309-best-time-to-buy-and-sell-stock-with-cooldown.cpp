class Solution {
private:
    int profitHelper(int i,vector<int> &prices,int buy,vector<vector<int>> &dp){
        if(i >= prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[i] + profitHelper(i,prices,0,dp),profitHelper(i+1,prices,1,dp));
        }
        else{
            profit = max(prices[i] + profitHelper(i+2,prices,1,dp),profitHelper(i+1,prices,0,dp));
        }
        return dp[i][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return profitHelper(0,prices,1,dp);
    }
};