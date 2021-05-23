class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> isSource(n, true);
        
        for(auto edge : edges)
            isSource[edge[1]] = false;
        
        vector<int> res;
        
        for(int i=0; i<isSource.size(); i++){
            if(isSource[i])
                res.push_back(i);   
        }
        return res;
    }
};