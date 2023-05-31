class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n-1;i++){
            int ind = i;
            for(int j = i;j < n;j++){
                if(nums[j] < nums[ind]) ind = j;
            }
            swap(nums[i],nums[ind]);
        }
    }
};