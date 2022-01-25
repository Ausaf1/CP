class Solution {
public:
    int helper(string s,int i,vector<int>& dp){
        if(s[i] == '0')
            return 0;
        if(i == s.length() || i == s.length()-1)
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        string t = s.substr(i,2);
        int one = helper(s,i+1,dp);
        int two = (stoi(t)>=1 && stoi(t)<=26) ? helper(s,i+2,dp) : 0;
        dp[i] = one + two;
        return dp[i];
    }
    
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        return helper(s,0,dp);
    }
};