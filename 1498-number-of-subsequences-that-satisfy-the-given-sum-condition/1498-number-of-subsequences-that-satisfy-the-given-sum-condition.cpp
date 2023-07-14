class Solution {
public:
int mod = 1e9 + 7;
    long help(int a,int b){
        if(a == 0 || a == 1) return a;
        if(b == 0) return 1;
        long ans = 1;
        if(b & 1){
            ans = a * help(a,b-1);
        }
        else{
            ans = help(a,b/2);
            ans *= ans;
        }
        return ans % mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int s = 0,e = n-1;
        int ans = 0;
        while(s <= e){
            if(nums[s] + nums[e] <= target){
                ans += help(2,e-s);
                ans %= mod;
                s++;
            }
            else e--;
        }
        return ans;
    }
};