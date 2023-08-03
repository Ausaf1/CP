class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n,0);
        queue<int> q;
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(visited[i]) continue;
            cnt++;
            q.push(i);
            visited[i] = 1;
            while(!q.empty()){
                int x = q.front();
                q.pop();
                for(auto it : adj[x]){
                    if(!visited[it]){
                        visited[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
        return cnt;
    }
};