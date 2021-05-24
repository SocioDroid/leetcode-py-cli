class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> v(n+1, 0);
        
        for(auto edge : edges){
            v[edge[0]]++;
            v[edge[1]]++;
        }
        
        for(int i=1; i<=n; i++){
            if(v[i] == n-1)
                return i;
        }
        return 0;
    }
};