class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
     vector<int> temp(n+1,0);
         int a = 0;
         for(int i = 0;i < n;i++){
             temp[nums[i]]++;
         }
        for(int i = 0;i < n+1;i++){
            if(temp[i] > 1)
                a = i;
        }
        return a;
    }
};