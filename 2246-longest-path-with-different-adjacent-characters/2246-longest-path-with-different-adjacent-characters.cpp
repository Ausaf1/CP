class Solution {
public: 
    vector<vector<int>> g;
    vector<int> longest,crossing;
     void dfs(int src,string& s){
        int &curr = longest[src];
        curr = 1;
        vector<int> all;
        for(auto c : g[src]){
            dfs(c,s);
            if(s[c] == s[src])
                continue;
            curr = max(curr,longest[c] + 1);
            all.push_back(longest[c]);
        }
        sort(all.begin(),all.end());
        if(all.size() > 1){
            int size = all.size();
            crossing[src] = all[size - 1] + all[size - 2]  + 1;
        }
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.length();
        g.clear();
        longest.clear(),crossing.clear();
        g.resize(n),longest.resize(n,0),crossing.resize(n,0);
        for(int j = 0;j < n;j++){
            if(parent[j] != -1)
                g[parent[j]].push_back(j);
        }
        dfs(0,s);
        int res = 0;
        for(int i = 0;i < n;i++){
            res = max(res,crossing[i]);
            res = max(res,longest[i]);
        }
        return res;
    }
};