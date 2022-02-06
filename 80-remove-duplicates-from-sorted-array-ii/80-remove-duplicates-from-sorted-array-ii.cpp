class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n =nums.size();
        int k = 1,j = 0;
        for(int i = 1;i < n;i++){
            if(nums[i]!=nums[j]){
                nums[++j] = nums[i];
                k = 1;
            }
            else if(nums[i] == nums[j] && k < 2){
                nums[++j] = nums[i];
                k++;
            }
        }
        return j+1;
    }
};