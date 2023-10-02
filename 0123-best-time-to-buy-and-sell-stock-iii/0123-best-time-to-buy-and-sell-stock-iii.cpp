class Solution {
private:
    int profitHelper(int i,vector<int> &prices,int buy,int n,int count,vector<vector<vector<int>>> &dp){
        if(i == n) return 0;
        if(count >= 2) return 0;
        if(dp[i][buy][count] != -1) return dp[i][buy][count];
        int profit = 0;
        if(buy){
            profit = max(-prices[i] + profitHelper(i,prices,0,n,count,dp),profitHelper(i+1,prices,1,n,count,dp));
        }
        else{
            profit = max(prices[i] + profitHelper(i+1,prices,1,n,count + 1,dp),profitHelper(i+1,prices,0,n,count,dp));
        }
        return dp[i][buy][count] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(2,vector<int>(3,0)));
        // return profitHelper(0,prices,1,n,0,dp);
        for(int i = n-1;i >= 0;i--){
            for(int buy = 0;buy <= 1;buy++){
                for(int count = 0;count < 2;count++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[i] + dp[i][0][count],dp[i+1][1][count]);
                    }
                    else{
                        profit = max(prices[i] + dp[i+1][1][count + 1],dp[i+1][0][count]);
                    }
                    dp[i][buy][count] = profit;
                }
            }
        }
    return dp[0][1][0];
    }
};