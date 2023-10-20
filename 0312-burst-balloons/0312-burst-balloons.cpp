class Solution {
private:
    int helper(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
        if(i > j) return 0;
        int mx = INT_MIN;
        if(dp[i][j] != -1) return dp[i][j];
        for(int idx = i;idx <= j;idx++){
            int cost = nums[i-1]*nums[idx]*nums[j+1] + helper(i,idx-1,nums,dp) + helper(idx+1,j,nums,dp);
            mx = max(mx,cost);
        }
        return dp[i][j] = mx;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(1,n,nums,dp);
    }
};