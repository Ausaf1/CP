class Solution {
private:
    int profitHelper(int i,vector<int> &prices,int n,int k,vector<vector<int>> &dp,int count){
        if(i == n) return 0;
        if(count == 2*k) return 0;
        if(dp[i][count] != -1) return dp[i][count];
        int profit = 0;
        if(count % 2 == 0){
            profit = max(-prices[i] + profitHelper(i,prices,n,k,dp,count + 1),profitHelper(i+1,prices,n,k,dp,count));
        }
        else{
            profit = max(prices[i] + profitHelper(i+1,prices,n,k,dp,count+1),profitHelper(i+1,prices,n,k,dp,count));
        }
        return dp[i][count] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
         vector<vector<int>> dp(n,vector<int>(2*k,-1));
        return profitHelper(0,prices,n,k,dp,0);
    }
};