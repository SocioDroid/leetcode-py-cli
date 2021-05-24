class Solution {
public:
    bool validPalindrome(string s) {
        // int i=0, j=s.length()-1;
        // int count=0;
        // while(i<=j)
        // {
        //     if(s[i] != s[j])
        //     {
        //         if(count == 1)
        //             return false;
        //         if(s[i] == s[j-1])
        //         {
        //             count++;
        //             j--;
        //         }
        //         else if(s[i+1] ==s[j])
        //         {
        //             i++;
        //             count++;
        //         }
        //         else
        //             return false;
        //     }
        //     i++;
        //     j--;
        // }
        // return true;
        int n = s.size(), h = (n) / 2; 
        for (int i = 0; i < h; ++i) {
            if (s[i] != s[n - 1 - i]) { 
                for (int j = i; j < h; ++j) { 
					if (s[j] != s[n - 1 -j -1] && s[j+1] != s[n - 1 - j])  
                        return false;
                }
                return true;  
            }
        }
        return true;  
    }
};