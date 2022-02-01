class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return n;
        int ans = 2;
        vector<vector<int>> dp(n,vector<int>(1001,1));
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                int diff = nums[j] - nums[i] + 500;
                dp[j][diff] = dp[i][diff] + 1;
                ans = max(ans, dp[j][diff]);
            }
        }
        return ans;
    }
};