class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        
        int res_len = INT_MAX;
        string ans = "";
        
        map<char, int> char_count;
        map<char, int> window_count;
        fillMap(char_count, t);
        
        int s_len = s.length();

        while(right < s_len){
            if(window_count.find(s[right]) == window_count.end())
                window_count[s[right]] = 1;
            else
                window_count[s[right]]++;
            
            // cout<<s.substr(left, right-left+1)<<"\t"<<left<<"\t"<<right<<endl;
            while(satisfies(char_count, window_count) && left <= right){
                if(right-left < res_len){
                    res_len = right - left;
                    ans = s.substr(left, right-left+1);
                }
                window_count[s[left]]--;
                left++;
            }
            right++;
        }
        return ans;
    }   
    
    bool satisfies(map<char, int>& char_count, map<char, int>& window_count){
        // cout<<"--------------------"<<endl;
        
        for(auto ch : char_count){
            if(ch.second > window_count[ch.first]){
                // cout<<"Satisfies : "<<false<<endl;        
                return false;
            }
            // cout<<ch.first<<"\t"<<ch.second<<"\t"<<window_count[ch.first]<<endl;
        }   
        // cout<<"Satisfies : "<<true<<endl;
        return true;
    }
    
    void fillMap(map<char, int>& char_count, string t){
        
        // cout<<"Initial map : "<<endl;
        for(int i=0; i<t.length(); i++){
            if(char_count.find(t[i]) == char_count.end())
                char_count[t[i]] = 0;
            char_count[t[i]]++;
        }
        
        // for(auto ch : char_count){
        //     cout<<ch.first<<"\t"<<ch.second<<"\t"<<endl;
        // }   
        // cout<<"--------------"<<endl;
    }
};