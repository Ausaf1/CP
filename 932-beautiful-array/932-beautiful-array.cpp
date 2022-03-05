class Solution {
public:
    vector<int> beautifulArray(int n) {
        if(n == 1)
            return {1};
        vector<int> ans;
        auto left = beautifulArray(n/2);
        auto right = beautifulArray(n - (n/2));
        for(auto i : left)
            ans.push_back(i*2);
        for(auto j : right)
            ans.push_back(j*2 - 1);
        return ans;
    }
};