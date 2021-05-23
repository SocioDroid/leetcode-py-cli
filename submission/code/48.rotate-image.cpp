class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size()-1;
        for(int i=0; i<matrix.size(); i++){
            for(int j=i; j<matrix[0].size(); j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        
        for(int i=0; i<matrix.size(); i++){
           for(int j=0; j<matrix[0].size()/2; j++)
            swap(matrix[i][j], matrix[i][n-j]);
        }
    }
};