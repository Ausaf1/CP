class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[n-1] = nums[n-1];
        priority_queue<pair<int,int>> maxx;
        maxx.push({dp[n-1],n-1});
        for(int i = n-2;i >= 0;i--){
            while(maxx.size() && maxx.top().second > i+k)
                maxx.pop();
            dp[i] = maxx.top().first + nums[i];
            maxx.push({dp[i],i});
        }
        return dp[0];
    }
};