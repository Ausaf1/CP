class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount + 1,0));
        for(int T = 0;T <= amount;T++){
            dp[0][T] = (T % coins[0]) == 0;
        }
        for(int i = 1;i < n;i++){
            for(int T = 0;T <= amount;T++){
                int notTake = dp[i-1][T];
                int take = 0;
                if(T >= coins[i]) take = dp[i][T - coins[i]];
                dp[i][T] = take + notTake;
            }
        }
        return dp[n-1][amount];
    }
};