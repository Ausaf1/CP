class Solution {
public:
    int helper(vector<int>& nums,int low,int high,int n){
        int mid = (low + high)/2;
        if((mid == 0 || nums[mid-1] <= nums[mid]) && (mid == n-1 || nums[mid+1] <= nums[mid]))
            return mid;
        else if(mid > 0 && nums[mid-1] > nums[mid])
            return helper(nums,low,mid-1,n);
        else
            return helper(nums,mid+1,high,n);
    }
    
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,0,n-1,n);
    }
};