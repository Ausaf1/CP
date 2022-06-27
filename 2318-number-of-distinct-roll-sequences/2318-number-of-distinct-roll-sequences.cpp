class Solution {
public:
    int dp[100001][7][7];
    int m = 1e9 + 7;
    
    int helper(int n,int last,int lastToLast){
        if(n == 0)
            return 1;
        if(dp[n][last][lastToLast] == 0){
            for(int j = 1;j < 7;j++)
                if(j != last && j != lastToLast && (last == 0 || gcd(j,last) == 1))
                    dp[n][last][lastToLast] = (dp[n][last][lastToLast] + helper(n-1,j,last))%m;
        }
        return dp[n][last][lastToLast];
    }
    
    int distinctSequences(int n) {
        return helper(n,0,0);
    }
};