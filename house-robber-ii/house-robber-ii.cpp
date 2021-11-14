class Solution {
public:
    
     int solve(vector<int>& nums, int i, int j){
     if ( i==j)return nums[i];
         vector< int> dp(nums.size()) ;
        
        /* Base case */
        dp[i] = nums[i];
        dp[i + 1] = max(nums[i + 1], nums[i]);
        
        for (int k = i + 2; k <= j; ++k)
           
         dp[k] = max(dp[k - 1], dp[k - 2] + nums[k]);
        
        return dp[j];
    }
    int rob(vector<int>& nums) {
        //take first one and not last
        //take last and not first
        int n =nums.size();
        if ( nums.size()==0)return 0;
        if (nums.size()==1)return nums[0];
        int start = solve(nums ,0,n-2);
        int end =solve(nums , 1, n-1);
        return max(start , end);
        
    }
};