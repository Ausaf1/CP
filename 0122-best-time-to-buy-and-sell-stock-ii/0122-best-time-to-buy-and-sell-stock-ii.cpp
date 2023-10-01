class Solution {
private:
    int profitHelper(int i,vector<int> &prices,bool buy,vector<vector<int>> &dp){
        if(i == prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[i] + profitHelper(i,prices,0,dp),profitHelper(i+1,prices,1,dp));
        }
        else{
            profit = max(prices[i] + profitHelper(i+1,prices,1,dp),profitHelper(i+1,prices,0,dp));
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1,vector<int>(2,-1));
        dp[n][0] = 0,dp[n][1] = 0;
        for(int i = n-1;i >= 0;i--){
            for(int buy = 0;buy <= 1;buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[i] + dp[i][0],dp[i + 1][1]);
                }
                else{
                    profit = max(prices[i] + dp[i + 1][1],dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};