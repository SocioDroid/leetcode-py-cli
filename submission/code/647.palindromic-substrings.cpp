class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                // cout<<i<<"\t"<<j<<endl;
                if(isPallindrome(s, i, j)){
                    count++;
                    // cout<<"True condition : "<<i<<"\t"<<j<<endl;

                }
            }
        }
        return count;
    }
    
    bool isPallindrome(string s, int i, int j){
        while(i<=j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};