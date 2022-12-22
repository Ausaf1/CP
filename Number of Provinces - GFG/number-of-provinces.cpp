//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,vector<int> adj[],vector<int> &visited){
        visited[node] = 1;
        for(auto it: adj[node]){
            if(!visited[it]) dfs(it,adj,visited);
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> visited(V,0);
        int cnt = 0;
        vector<int> adjl[V];
        for(int i = 0;i < V;i++){
            for(int j = 0;j < V;j++){
                if(adj[i][j] == 1 && i != j){
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }
        for(int i = 0;i < V;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,adjl,visited);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends