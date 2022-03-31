class Solution {
public:
    bool helper(int mid,vector<int>& nums,int m){
        int sum = 0,c = 0;
        for(int i = 0;i <nums.size();i++){
            if(nums[i] > mid)
                return false;
            sum += nums[i];
            if(sum > mid){
                c++;
                sum = nums[i];
            }
        }
        c++;
        if(c <= m)
            return true;
        return false;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int l = 0,r = 0;
        int ans = 0;
        for(int i = 0;i < nums.size();i++){
            l = max(l,nums[i]);
            r += nums[i];
        }
        while(l <= r){
            int mid = (l + r)/2;
            if(helper(mid,nums,m)){
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};