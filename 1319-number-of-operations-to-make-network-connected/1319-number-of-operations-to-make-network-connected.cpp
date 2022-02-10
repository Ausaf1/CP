class Solution {
    
    void dfs(unordered_map<int,vector<int>>& adj,int curr,vector<bool>& visited){
        visited[curr] = true;
        for(auto i : adj[curr]){
            if(!visited[i])
                dfs(adj,i,visited);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>> adj;
        vector<bool> visited(n,false);
        int edges = 0;
        for(int i = 0;i < connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            edges+=1;
        }
        int c = 0;
        for(int i = 0;i < n;i++){
            if(!visited[i]){
                c+=1;
                dfs(adj,i,visited);
            }
        }
        if(edges < n-1)
            return -1;
        int r = edges - ((n-1) - (c-1));
        if(r >= c-1)
            return c-1;
        return -1;
    }
};