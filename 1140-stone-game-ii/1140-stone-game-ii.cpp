class Solution {
public:
    int dp[101][201];
        int helper(int i,int M,vector<int>& piles){
        if(i >= piles.size()) return 0; 
        if(dp[i][M] != -1) return dp[i][M]; 
        int total = 0, ans = INT_MIN;
        for(int j=0; j<2*M; j++){ 
            if(i+j < piles.size()) total += piles[i+j]; 
            ans = max(ans, total-helper(i+j+1,max(j+1,M),piles)); 
        }     
        return dp[i][M] = ans;
    }
    
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
         int sum = accumulate(piles.begin(), piles.end(), 0);
        int diff = helper(0,1,piles);
        return (sum + diff)/2;
    }
};