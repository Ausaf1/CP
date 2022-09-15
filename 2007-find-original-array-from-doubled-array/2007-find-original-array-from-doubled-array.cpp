class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if( n & 1)
            return {};
        unordered_map<int,int> mp;
        sort(changed.begin(),changed.end());
        for(auto c : changed)
            mp[c]++;
        vector<int> res;
        for(auto c : changed){
            if(mp[c] == 0)
                continue;
            if(mp[2*c] == 0)
                return {};
            res.push_back(c);
            mp[c]--;
            mp[2*c]--;
        }
        return res;
    }
};