class Solution {
public:
    // Dijkstra
    vector<vector<int>> directions = {{-1,0},{0,-1},{0,1},{1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        using p = pair<int,pair<int,int>>;
        priority_queue<p,vector<p>,greater<p>> pq;
        int row  = heights.size(),col = heights[0].size();
        vector<vector<int>> dist(row,vector<int>(col,INT_MAX));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto n = pq.top();
            pq.pop();
            int wt = n.first,r = n.second.first,c = n.second.second;
            if(dist[r][c] < wt)
                continue;
            if(r == row - 1 && c == col - 1)
                return wt;
            for(auto &dir : directions){
                int dr = r + dir[0];
                int dc = c + dir[1];
                if(dr < 0 || dr >= row)
                    continue;
                if(dc < 0 || dc >= col)
                    continue;
                int newWeight = abs(heights[r][c] - heights[dr][dc]);
                newWeight = max(newWeight,wt);
                if(dist[dr][dc] <= newWeight)
                    continue;
                dist[dr][dc] = newWeight;
                pq.push({newWeight,{dr,dc}});
            }
        }
        return 0;
    }
};