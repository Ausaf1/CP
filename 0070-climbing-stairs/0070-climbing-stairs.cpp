class Solution {
private:
    long long m = 1e18;
    int findWays(int idx,vector<int> &dp){
        if(idx == 0 || idx == 1) return 1;
        if(dp[idx] != -1) return dp[idx];
        int step1 = findWays(idx - 1,dp);
        int step2 = findWays(idx - 2,dp);
        return dp[idx] = (step1 + step2) % m;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1,-1);
        return findWays(n,dp) % m;
    }
};