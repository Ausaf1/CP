class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     int q=0;
    for(int p=m;p<n+m;p++) {
        nums1[p]=nums2[q++];
    }
    sort(nums1.begin(), nums1.end());
    }
};