class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
    
    bool solve(vector<vector<char>>& board, int row, int col){
        int n=board.size();
        
        if(row >= n)
            return true;
        
        if(col>=n)
            return solve(board, row+1, 0);

        if(board[row][col] != '.')
            return solve(board, row, col+1);
        
         for(char c = '1'; c<='9'; c++){
             board[row][col] = c;
             if(check(board, row, col)){
                 if(solve(board, row, col + 1))
                    return true;
             }
         } 
         board[row][col] = '.';
        return false;
    }
    
    bool check(vector<vector<char>>& board, int row, int col){
        for(int j = 0; j<board[0].size(); j++){
            if(j != col && board[row][j] == board[row][col]){
                return false;
            }
        }
        
        
        for(int i=0; i<board.size(); i++){
            if(i != row && board[i][col] == board[row][col]){
                return false;
            }
        }
        
        int startRow = (row/3)*3;
        int startCol = (col/3)*3;
        
        for(int i=startRow; i<startRow+3; i++){
            for(int j=startCol; j<startCol+3; j++){
                if(i == row && j == col)
                    continue;
                if(board[i][j] == board[row][col])
                    return false;
            }
        }
        return true;
    }
};