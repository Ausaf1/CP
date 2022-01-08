class Solution {
public:

    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        int a, n;
        n = nums.size();   
        if(n == 1)
            return nums[0] > 0;
        int neg = 0;
        int fNeg = -1;
        int zero = -1;
        for(int i=0; i<n; i++) {
            a = nums[i];
            if(a == 0) {
                neg = 0;
                fNeg = -1;
                zero = i;
                continue;
            }
            if(a < 0) {
                if(fNeg == -1) {
                    fNeg = i;
                }
                neg++;
            }
            if(neg % 2 == 0) {
                ans = max(ans, i - zero);
            } else {
                ans = max(ans, i - fNeg);
            }
        }
        return ans;
    }
    
};