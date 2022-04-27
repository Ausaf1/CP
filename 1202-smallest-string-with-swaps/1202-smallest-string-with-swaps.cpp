class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    void dfs(int i,vector<int> &idx,vector<char> &letters,string &s){
        visited[i] = true;
        idx.push_back(i);
        letters.push_back(s[i]);
        for(int u : graph[i]){
            if(!visited[u])
                dfs(u,idx,letters,s);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        graph.resize(n);
        visited.resize(n,false);
        for(auto j : pairs){
            graph[j[0]].push_back(j[1]);
            graph[j[1]].push_back(j[0]);
        }
        for(int i = 0;i < n;i++){
            vector<int> idx;
            vector<char> letters;
            if(!visited[i]){
                dfs(i,idx,letters,s);
            }
            sort(idx.begin(),idx.end());
            sort(letters.begin(),letters.end());
            for(int i = 0;i < idx.size();i++)
                s[idx[i]] = letters[i];
        }
        return s;
    }
};