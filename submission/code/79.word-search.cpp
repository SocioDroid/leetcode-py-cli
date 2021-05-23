class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == word[0])
                    if(isExist(board, word, 1, i, j))
                        return true;
            }
        }
        return false;
    }
    
    bool isExist(vector<vector<char>>& board, string word, int index, int i, int j){
        char val = board[i][j];
        board[i][j] = ' ';
        // cout<<"Foe char : "<<word[index]<<endl;
        if(index >= word.length())
            return true;
        
        if(i-1 >= 0 && board[i-1][j] == word[index]){
            // cout<<"In 1st IF"<<endl;
            if(isExist(board, word, index+1, i-1, j))
                return true;
        }
        
        if(j-1 >= 0 && board[i][j-1] == word[index]){
            // cout<<"In 2nd IF"<<endl;
            if(isExist(board, word, index+1, i, j-1))
                return true;
        }
        
        if(i+1 < board.size() && board[i+1][j] == word[index]){
            if(isExist(board, word, index+1, i+1, j))
                return true;
        }
        
        
        if(j+1 < board[0].size() && board[i][j+1] == word[index]){
            // cout<<"In 4th IF"<<endl;
            if(isExist(board, word, index+1, i, j+1))
                return true;
        }
        
        board[i][j] = val;
        return false;
    }
};