class Solution {
public:
    
    bool possible(int mid,vector<int> &arr,int limit,int n){
	int sum = 0;
	for(int i = 0;i < n;i++){
		sum += ceil((double)arr[i]/(double)mid);
	}
	if(sum <= limit) return true;
	return false;
}
    
    int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
	int mx = -1e9,ans = 0;
	for(int i = 0;i < n;i++) mx = max(mx,nums[i]);
	int low = 1,high = mx;
	while(low <= high){
		int mid = (low + high) >> 1;
		if(possible(mid,nums,threshold,n)){
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	} 
	return ans;
    }
};