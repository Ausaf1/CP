class Solution {
public:
    
    int firstOccurance(vector<int>& nums, int target,int low,int high,int ans){
         if(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                ans = mid;
                return firstOccurance(nums,target,low,mid-1,ans);
            }
            else if(nums[mid]>target){
                return firstOccurance(nums,target,low,mid-1,ans);
            }
            else{
                return firstOccurance(nums,target,mid+1,high,ans);
            }
         }
        return ans;
    }
    
    int lastOccurance(vector<int>& nums, int target,int low,int high,int ans){
        if(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                ans = mid;
                return lastOccurance(nums,target,mid+1,high,ans);
            }
            else if(nums[mid]>target){
                return lastOccurance(nums,target,low,mid-1,ans);
            }
            else{
                return lastOccurance(nums,target,mid+1,high,ans);
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int f = firstOccurance(nums,target,0,n-1,-1);
        int l = lastOccurance(nums,target,0,n-1,-1);
        return {f,l}; 
    }
};