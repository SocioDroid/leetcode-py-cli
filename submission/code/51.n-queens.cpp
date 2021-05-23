class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<int> q_pos (n, -1);
        int curr = 0;
        
        vector<vector<string>> chess;
        bool isFound;
        string dot = "";
        for(int i=0; i<n; i++)
            dot += ".";

        vector<string> res(n, dot);
        while(curr > -1){
            cout<<curr<<endl;
            isFound = false;
            for(int i=q_pos[curr]+1; i<n; i++){
                cout<<"In for "<<i<<endl;
                isFound = isValid(q_pos, i, curr);
                if(isFound){
                    q_pos[curr] = i;
                    curr++;
                    break;
                }
            }
            if(curr == n)
            {
                print(q_pos);
                for(int k=0; k<q_pos.size(); k++)
                   res[k][q_pos[k]] = 'Q';
                
                chess.push_back(res);
                
                for(int k=0; k<q_pos.size(); k++)
                    res[k][q_pos[k]] = '.';
                
                curr--;;
            }
            if(!isFound){
                q_pos[curr] = -1;
                curr--;   
            }
                
        }
         
        return chess;
    }
    
    void print(vector<int> q_pos){
        for(auto i : q_pos)
            cout<<i<<"\t";
        cout<<endl;
    }
    
    bool isValid(vector<int> q_pos, int i, int curr){
        for(int k=0; k<q_pos.size(); k++){
            if(i == q_pos[k] || (curr-k) == abs(q_pos[k] - i))
                return false;
        }
        return true;
    }
};