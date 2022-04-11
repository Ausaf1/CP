class Solution {
public:
    int dp[1001][1001];
    int helper(string &s1, string &s, int i, int j){
        if(i == 0 || j == 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i-1] == s[j-1])
            return dp[i][j] = 1 + helper(s1,s,i-1,j-1);
        else
            return dp[i][j] = max(helper(s1,s,i-1,j),helper(s1,s,i,j-1));
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string s1 = s;
        memset(dp,-1,sizeof(dp));
        reverse(s1.begin(),s1.end());
        return helper(s1,s,n,n);
    }
};