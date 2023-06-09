class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> s;
        int ans = 1,cnt = 1;
        for(auto i : nums)
            s.insert(i);
        for(auto it : s){
            if(s.find(it - 1) == s.end()){
                int x = it;
                cnt = 1;
                while(s.find(x + 1) != s.end()){
                    x++;
                    cnt++;
                }
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};