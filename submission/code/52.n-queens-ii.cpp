class Solution {
public:
    int totalNQueens(int n) {
        vector<int> qplace(n, -1);
        int res = 0;
        solve(qplace, 0, res);
        return res;
    }
    
    bool solve(vector<int>& qplace, int row, int& res){
        int len = qplace.size();
        
        if(row == len){
           res++;
            return false;
        }
        
        
        for(int i=0; i<len; i++){
            if(check(qplace, row, i)){
                qplace[row] = i;
                if(solve(qplace, row+1, res))
                    return true;
            }
        }
        qplace[row] = -1;
        return false;
    }
    
    bool check(vector<int>& qplace, int row, int col){
        for(int k=0; k<qplace.size(); k++){
            if(col == qplace[k] || (row-k) == abs(col-qplace[k]))
                return false;
        }
        return true;
    }
};