class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size());
        for(int i = 0; i < graph.size();i++){
            if(color[i] == 0){
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty()){
                    int a = q.front();
                    q.pop();
                    for(int j : graph[a]){
                        if(color[j] == color[a])
                            return false;
                        else if(color[j] == 0){
                            q.push(j);
                            color[j] = -color[a];
                        }
                    }
                }
            }
        }
        return true;
    }
};