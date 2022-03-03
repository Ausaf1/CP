class Solution {
public:
    int count = 0;
    
    bool isSafe(int row,int col,int n,vector<string>& board){
        for(int i = 0;i < row;i++){
            if(board[i][col] == 'Q')
                return false;
        }
        for(int i = row-1,j = col-1;i >= 0 && j >= 0;i--,j--){
            if(board[i][j] == 'Q')
                return false;
        }
        for(int i = row-1,j = col+1;i >= 0 && j < n;i--,j++){
             if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    
    void placeQueens(int row,int n,vector<string>& board){
        if(row == n){
            count++;
            return;
        }
        for(int i = 0;i < n;i++){
            if(isSafe(row,i,n,board)){
                board[row][i] = 'Q';
                placeQueens(row+1,n,board);
                board[row][i] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        placeQueens(0,n,board);
        return count;
    }
};