class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> vi;
        set<int> vj;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                if(!matrix[i][j])
                {
                    vi.insert(i);
                    vj.insert(j);
                }
            }
        }
        set<int>::iterator itr;
        for (itr = vi.begin(); itr != vi.end(); itr++)
        {
            for(int j=0; j<matrix[*itr].size(); j++)
            {
                matrix[*itr][j] = 0;
            }
        }
        
        for (itr = vj.begin(); itr != vj.end(); itr++)
        {
            for(int j=0; j<matrix.size(); j++)
            {
                matrix[j][*itr] = 0;
            }
        }
           
    }
};