//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &ans,int newColor,int delRow[],int delCol[],vector<vector<int>> &image,int iniColor){
        ans[r][c] = newColor;
        int n = ans.size(),m = ans[0].size();
        for(int i = 0;i < 4;i++){
            int nr = r + delRow[i];
            int nc = c + delCol[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == iniColor && ans[nr][nc] != newColor){
                dfs(nr,nc,ans,newColor,delRow,delCol,image,iniColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,-1,0,+1};
        dfs(sr,sc,ans,newColor,delRow,delCol,image,iniColor);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends