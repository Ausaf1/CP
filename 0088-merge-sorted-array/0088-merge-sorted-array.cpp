class Solution {
public:
    void swapIfGreater(vector<int> &nums1,vector<int> &nums2,int left,int right){
        if(nums1[left] > nums2[right]) swap(nums1[left],nums2[right]);
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        int gap = len/2 + len%2;
        while(gap > 0){
            int left = 0,right = left + gap;
            while(right < len){
                if(left < m && right >= m){
                    swapIfGreater(nums1,nums2,left,right - m);
                }
                else if(left >= m){
                    swapIfGreater(nums2,nums2,left - m,right - m);
                }
                else{
                    swapIfGreater(nums1,nums1,left,right);
                }
                left++,right++;
            }
            if(gap == 1) break;
            gap = gap/2 + gap%2;
        }
        for(int i = m;i < m + n;i++) nums1[i] = nums2[i - m];
    }
};