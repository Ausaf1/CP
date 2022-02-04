class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int current;
        int n = stoneValue.size();
        vector<int> dp(3,0);
        for(int i = n-1;i >= 0;i--){
            current = 0;
            int ans = INT_MIN;
            for(int j = 0;j < 3 && i+j < n;j++){
                current += stoneValue[i+j];
                ans = max(ans,current - dp[j]);
            }
            dp[2] = dp[1];
            dp[1] = dp[0];
            dp[0] = ans;
        }
        if(dp[0] == 0)
            return "Tie";
        else if(dp[0] > 0)
            return "Alice";
        else
            return "Bob";
    }
};