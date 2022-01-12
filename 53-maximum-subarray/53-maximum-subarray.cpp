class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = INT_MIN,max_end = 0;
        for(int i = 0;i < nums.size();i++){
            max_end+=nums[i];
            if(maximum < max_end){
                maximum = max_end;
            }
            if(max_end < 0)
                max_end = 0;
        }
        return maximum;
    }
};