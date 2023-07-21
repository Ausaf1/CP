class Solution {
private:
    int f(string word1, string word2,int i,int j,vector<vector<int>> &dp){
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = f(word1,word2,i-1,j-1,dp);
        return dp[i][j] = 1 + min(f(word1,word2,i-1,j-1,dp),min(f(word1,word2,i-1,j,dp),f(word1,word2,i,j-1,dp)));
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(),n2 = word2.length();  
        vector<vector<int>> dp(n1,vector<int>(n2,-1));  
        return f(word1,word2,n1-1,n2-1,dp);
    }
};