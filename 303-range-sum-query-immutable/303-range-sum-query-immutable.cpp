class NumArray {
     vector<int> pref;
public:
   
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pref.push_back(0);
        int sum = 0;
        for(int i = 0;i < n;i++)
           sum += nums[i],pref.push_back(sum);
    }
    
    int sumRange(int left, int right) {
        return pref[right + 1] - pref[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */