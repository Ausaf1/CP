class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms,vector<bool>& v,int j){
        if(v[j])
            return;
        v[j] = true;
        for(int i = 0;i < rooms[j].size();i++){
            dfs(rooms,v,rooms[j][i]);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> v(n+1);
       dfs(rooms,v,0);
        for(int i = 0;i < n;i++){
            if(!v[i])
                return false;
        }
        return true;
    }
};