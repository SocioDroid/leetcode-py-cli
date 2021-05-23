class Solution {
public:
    string shortestPalindrome(string s) {
        if(s == "")
            return "";
        
        string temp(s);
        string rev(s);
        reverse(rev.begin(),rev.end());
        s += "#" + rev;
        vector<int> lookup(s.length());

        int i = 1;
        int j = 0;
        while(i<s.length()){
            if(s[i] == s[j])
            {
                lookup[i] = j+1;
                i++, j++;
            }
            else{
                if(j!=0){
                    j = lookup[j-1];
                }else{
                    lookup[i] = 0;
                    i++;
                }
            }
        }
        

        for(auto i: lookup)
            cout<<i<<"\t";
        
        return rev.substr(0, rev.length() - lookup[s.length()-1]) + temp;
    }
};