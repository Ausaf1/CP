class Solution {
private:
    bool f(int idx,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(target == 0) return true;
        if(idx == 0) return nums[idx] == target;
        if(dp[idx][target] != -1) return dp[idx][target];
        bool take = false;
        if(target >= nums[idx]) take = f(idx - 1,target - nums[idx],nums,dp);
        bool notTake = f(idx - 1,target,nums,dp);
        return dp[idx][target] = take | notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum & 1) return false;
        int n = nums.size();
        vector<vector<int>> dp(n + 1,vector<int>(sum/2 + 1,-1));
        return f(n-1,sum/2,nums,dp);
    }
};