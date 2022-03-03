class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        int s = 0,p = 0;
        for(int i = 2;i < n;i++){
            s += (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) ? ++p : (p = 0);
        }
        return s;
    }
};