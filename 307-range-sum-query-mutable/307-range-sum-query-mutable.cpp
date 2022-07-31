class NumArray {
public:
    vector<int> prefix;
    int sum;
    NumArray(vector<int>& nums) {
        sum = 0;
        for(int i = 0;i < nums.size();i++){
            prefix.push_back(nums[i]);
            sum+=nums[i];
        }
    }
    
    void update(int index, int val) {
        sum -= prefix[index];
        prefix[index] = val;
        sum += val;
    }
    
    int sumRange(int left, int right) {
        int ans = sum;
        for(int i = 0;i < left;i++){
            ans -= prefix[i];
        }
        for(int i = right + 1;i < prefix.size();i++)
            ans -= prefix[i];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */