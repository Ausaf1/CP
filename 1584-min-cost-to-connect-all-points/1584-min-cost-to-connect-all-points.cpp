class Solution {
public:
    vector<int> parent;
    int findParent(int a){
        if(parent[a] < 0)
            return a;
        return parent[a] = findParent(parent[a]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(1001,-1);
        vector<pair<int, pair<int,int>>> adj;
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj.push_back({w,{i,j}});
            }
        }
        sort(adj.begin(),adj.end());
        int sum = 0;
        for(int i = 0;i < adj.size();i++){
            int a = findParent(adj[i].second.first);
            int b = findParent(adj[i].second.second);
            if(a != b){
                sum += adj[i].first;
                parent[a] = b;
            }
        }
        return sum;
    }
};