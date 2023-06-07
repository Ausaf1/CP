class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int negIdx = 1,posIdx = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(nums[i] >= 0) ans[posIdx] = nums[i],posIdx += 2;
            else ans[negIdx] = nums[i],negIdx += 2;
        }
        return ans;
    }
};