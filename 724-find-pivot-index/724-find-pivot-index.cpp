class Solution {
public:
    int pivotIndex(vector<int>& nums) {
     int l = 0,r = 0;
        if(nums.size()==1)
            return 1;
        for(int i = 0;i < nums.size();i++){
            r+=nums[i];
        }
        for(int i = 0;i < nums.size();i++){
            r-=nums[i];
            if(l == r){
               return i;
            }
            l+=nums[i];
        }
        return -1;
    }
};