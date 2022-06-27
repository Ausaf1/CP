class Solution {
public:
    int maxSubarraySum(vector<int> &arr){
        int n = arr.size();
        int max_so_far = INT_MIN,max_ending = 0;
        for(int i = 0;i < n;i++){
            max_ending = max_ending + arr[i];
            if(max_so_far < max_ending)
                max_so_far = max_ending;
            if(max_ending < 0)
                max_ending = 0;
        }
        return max_so_far;
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> first(n,0),second(n,0);
        int sum1 = accumulate(nums1.begin(),nums1.end(),0);
        int sum2 = accumulate(nums2.begin(),nums2.end(),0);
        for(int i = 0;i < n;i++)
            first[i] = nums1[i]-nums2[i],second[i] = nums2[i] - nums1[i];
        int ans1 = maxSubarraySum(first) + sum2;
        int ans2 = maxSubarraySum(second) + sum1;
        return max(ans1,ans2);
    }
};