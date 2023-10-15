class Solution {
private:
    int f(int steps,int i,int mod,int n,vector<vector<int>> &dp){
        if(steps == 0){
            if(i == 0) return 1;
            return 0;
        }
        if(i >= n || i < 0 || steps < 0) return 0;
        if(dp[i][steps] != -1) return dp[i][steps];
        long long ways = f(steps - 1,i + 1,mod,n,dp) % mod;
        ways += f(steps - 1,i - 1,mod,n,dp) % mod;
        ways += f(steps - 1,i,mod,n,dp) % mod;
        return dp[i][steps] = (int)(ways % mod);
    }
public:
    int numWays(int steps, int arrLen) {
        int mod = 1e9+7;
        vector<vector<int>> dp(min(arrLen,steps),vector<int>(steps + 1,-1));
        return f(steps,0,mod,arrLen,dp);
    }
};