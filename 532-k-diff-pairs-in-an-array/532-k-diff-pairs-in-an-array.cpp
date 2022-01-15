class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       unordered_map<int,int> m;
        int count = 0;
        for(auto x : nums)
            m[x]++;
        if(k == 0){
            for(auto i : m){
                if(i.second >1)
                    count++;
            }
            return count;
        }
        for(auto i : m){
            if(m.count(i.first-k))
                count++;
        }
        return count;
    }
};