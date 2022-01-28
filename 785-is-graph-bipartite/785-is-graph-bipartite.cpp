class Solution {
public:
    bool valid(vector<vector<int>>& graph, vector<int> &color,int c,int n){
        if(color[n]!=0)
            return color[n] == c;
        color[n] = c;
        for(int i : graph[n]){
            if(!valid(graph,color,-c,i))
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size());
        for(int i = 0;i < graph.size();i++){
            if(color[i] == 0 && !valid(graph,color,1,i))
                return false;
        }
        return true;
    }
};