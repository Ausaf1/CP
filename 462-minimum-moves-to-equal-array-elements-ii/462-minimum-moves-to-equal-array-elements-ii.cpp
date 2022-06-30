class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        nth_element(nums.begin(),nums.begin() + n/2,nums.end());
        int m = nums[n/2];
        for(int i = 0;i < n;i++)
            ans += abs(nums[i] - m);
        return ans;
    }
};