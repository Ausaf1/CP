class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(),i = 0;
        int res = 0;
        while(i < n){
            int cnt = 0;
            while(i < n && nums[i] == 1) cnt++,i++;
            res = max(res,cnt);
            i++;
        }
        return res;
    }
};