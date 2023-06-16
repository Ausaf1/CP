class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long res = -1e9,pre = 0,suff = 0;
        for(int i = 0;i < n;i++){
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;
            pre = pre*nums[i];
            suff = suff*nums[n-i-1];
            res = max(res,max(pre,suff));
        }
        return (int)res;
    }
};