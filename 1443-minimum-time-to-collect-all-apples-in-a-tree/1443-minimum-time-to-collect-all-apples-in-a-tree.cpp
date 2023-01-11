class Solution {
public:
    vector<vector<int>> adj;
    int dfs(vector<bool>& hasApple,int node,int prev)
    {
        int ans=0;
        int t;
        for(int &i:adj[node])
	    if(i != prev)
	    {
	        t=dfs(hasApple,i,node);
            if(hasApple[i]){
                ans += (2 + t);
                hasApple[node] = true;
            }
	    }
        return ans; 
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        adj.resize(n);
        for(vector<int> &e:edges)
            adj[e[0]].push_back(e[1]),adj[e[1]].push_back(e[0]);
        return dfs(hasApple,0,0);
    }
};