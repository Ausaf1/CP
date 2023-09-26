class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        queue<pair<int, int>> q;
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n + 1,1e9);
        q.push({k, 0});
        dist[k] = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int from = it.first;
            int wt = it.second;
            for (auto adjNode : adj[from]) {
            int to = adjNode.first;
            int curr = adjNode.second;
            //   cout << curr << endl;
            if(curr + wt < dist[to]){
                dist[to] = curr + wt;
                q.push({to,curr + wt});
            }
            }
        }
        int res = 0;
        for (int i = 1;i <= n;i++) {
            if (dist[i] == 1e9)
            return -1;
            else res = max(res,dist[i]);
        }
        return res;
    }
};