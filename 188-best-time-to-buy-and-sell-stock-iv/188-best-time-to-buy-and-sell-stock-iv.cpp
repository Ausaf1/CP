class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k == 0 || n <=1)
            return 0;
        if(2*k > n){
            int ans = 0;
            for(int i = 1;i < n;i++){
                if(prices[i] > prices[i-1])
                    ans += (prices[i] - prices[i-1]);
            }
            return ans;
        }
        vector<int> dp(2*k+1,0);
        dp[0] = -prices[0];
        for(int i = 1;i <= 2*k;i++){
            if(i % 2 == 0)
                dp[i] = INT_MIN;
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j <= 2*k;j++){
                if(j == 0)
                    dp[j] = max(dp[j],-prices[i]);
                else if(j % 2 == 0)
                    dp[j] = max(dp[j],dp[j-1] - prices[i]);
                else
                    dp[j] = max(dp[j],dp[j-1] + prices[i]);
            }
        }
        return dp[2*k-1];
    }
};