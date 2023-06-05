class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(),j = 0,cnt = 0,res = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] == 0) cnt++;
            if(cnt > k){
                while(nums[j] != 0) j++;
                j++;
                cnt--;
            }
            res = max(res,i - j + 1);
        }
        return res;
    }
};