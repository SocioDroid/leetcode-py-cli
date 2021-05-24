class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        
        for(int i=0; i<s.length(); i++){
            int len1 = pallindrome(s, i, i+1);
            int len2 = pallindrome(s, i, i);
            int len = max(len1, len2);
            if(len > end -start){
                end = i + (len / 2);
                start = i - (len-1) / 2;
            }
        }
        return s.substr(start, end-start+1);
    }
    
    int pallindrome(string s, int left, int right){
        while(left > -1 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
};