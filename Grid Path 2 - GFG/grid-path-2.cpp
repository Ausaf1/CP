//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        int mod = 1e9 + 7;
        vector<int> prev(m,0);
        for(int i = 0;i < n;i++){
            vector<int> curr(m,0);
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 1) curr[j] = 0;
                else if(i == 0 && j == 0) curr[j] = 1;
                else{
                    int up = 0,left = 0;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = curr[j-1];
                    curr[j] = (up + left) % mod;
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends