class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> v = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                int c = 0;
                for(auto k : v){
                    int a = i+k[0];
                    int b = j+k[1];
                    if(a >= 0 && a < m && b >=0 && b < n && (board[a][b] == 1 || board[a][b] == 2))
                        c++;
                }
                if(board[i][j] == 1){
                    if(c < 2 || c > 3)
                        board[i][j] = 2;
                }
                else{
                    if(c == 3){
                        board[i][j] = 3;
                    }
                }
            }
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++)
                board[i][j] %= 2;
        }
    }
};