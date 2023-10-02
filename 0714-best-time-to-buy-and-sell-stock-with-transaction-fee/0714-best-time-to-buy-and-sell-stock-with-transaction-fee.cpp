class Solution {
private:
    int profitHelper(int i,vector<int> &prices,int fee,int buy,vector<vector<int>> &dp){
        if(i >= prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[i] + profitHelper(i,prices,fee,0,dp),profitHelper(i+1,prices,fee,1,dp));
        }
        else{
            profit = max(prices[i] - fee + profitHelper(i+1,prices,fee,1,dp),profitHelper(i+1,prices,fee,0,dp));
        }
        return dp[i][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return profitHelper(0,prices,fee,1,dp);
    }
};