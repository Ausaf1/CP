class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[n];
        map<int,int> indegree;
        for(auto it: relations){
            adj[it[0] - 1].push_back(it[1] - 1);
            indegree[it[1] - 1]++;
        }
        queue<pair<int,int>> pq;
        for(int i = 0;i < n;i++){
            if(indegree[i] == 0) pq.push({i,time[i]});
        }
        int ans = 0;
        vector<int> dist = time;
        // dist.insert(dist.begin(),0);
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            int node = it.first;
            int t = it.second;
            for(auto i : adj[node]){
                dist[i] = max(dist[i],t + time[i]);
                indegree[i]--;
                if(indegree[i] == 0) pq.push({i,dist[i]});
            }
        }
        sort(dist.begin(),dist.end());
        return dist[n-1];
    }
};