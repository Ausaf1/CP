class Solution {
public:
    vector<int> ans;
    vector<int> dfs(int node,vector<int> adj[],string &labels,int parent){
        vector<int> cnt(26,0);
        for(auto x : adj[node]){
            if(x != parent){
                auto t = dfs(x,adj,labels,node);
                for(int i = 0;i < 26;i++) cnt[i] += t[i];
            }
        }
        cnt[labels[node] - 'a']++;
        ans[node] = cnt[labels[node] - 'a'];
        return cnt;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n);
        vector<int> adj[n];
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0,adj,labels,-1);
        return ans;
    }
};