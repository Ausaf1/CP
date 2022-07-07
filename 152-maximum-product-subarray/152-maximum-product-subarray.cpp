class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p1,p2,ans;
        p1 = p2 = ans = nums[0];
        int n = nums.size();
        for(int i = 1;i < n;i++){
            int t = max(nums[i],max(p1*nums[i],p2*nums[i]));
            p2 = min(nums[i],min(p1*nums[i],p2*nums[i]));
            p1 = t;
            ans = max(ans,p1);
        }
        return ans;
    }
};