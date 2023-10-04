//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class DSU{
    vector<int> parent,rank;
    public: 
        DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 0;i <= n;i++) parent[i] = i;
    }
    
    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u,int v){
        int par_u = findUPar(u);
        int par_v = findUPar(v);
        if(par_u == par_v) return;
        if(rank[par_u] < rank[par_v]) parent[par_u] = par_v;
        else if(rank[par_v] < rank[par_u]) parent[par_v] = par_u;
        else{
            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DSU ds(n);
        int cntExtras = 0;
        for(it : edge){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)) cntExtras++;
            else ds.unionByRank(u,v);
        }
        int cntC = 0;
        for(int i = 0; i < n;i++){
            if(ds.findUPar(i) == i) cntC++;
        }
        if(cntExtras >= cntC-1) return (cntC - 1);
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends