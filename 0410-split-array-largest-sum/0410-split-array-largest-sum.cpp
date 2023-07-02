class Solution {
private:
    int func(int mid,vector<int> &nums,int n){
        int cnt = 1,sum = 0;
        for(int i = 0;i < n;i++){
            if(sum + nums[i] <= mid) sum += nums[i];
            else{
                sum = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low <= high){
            int mid = (low + high) >> 1;
            int count = func(mid,nums,n);
            // if(count == k) high = mid - 1;
            if(count > k) low = mid + 1;
            else high = mid - 1; 
        }   
        return low;                 
    }
};