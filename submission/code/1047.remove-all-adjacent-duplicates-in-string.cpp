class Solution {
public:
    string removeDuplicates(string S) {
        string s;
        s.push_back(S[0]);
        for(int i=1;i<S.length(); i++)
        {
            if(s.back() == S[i])
                s.pop_back();   
            else
                s.push_back(S[i]);
            
        }
        return s;
    }
};