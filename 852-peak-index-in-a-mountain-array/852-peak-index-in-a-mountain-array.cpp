class Solution {
public:
    int helper(vector<int>& arr,int low,int high,int n){
        int mid = (low + high)/2;
        int ans = 0;
        if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid]))
            return mid;
        else if(mid > 0 && arr[mid-1] > arr[mid])
            ans = helper(arr,low,mid-1,n);
        else
            ans = helper(arr,mid+1,high,n);
        return ans;
    }
    
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        return helper(arr,0,n-1,n);
    }
};