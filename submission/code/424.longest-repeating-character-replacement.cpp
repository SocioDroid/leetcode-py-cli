class Solution {
public:
    int characterReplacement(string s, int k) {
//         vector char_count(26, 0); 
//         int window_start = 0, max_length = 0, max_count = 0;
        
//         for(int window_end=0; window_end<s.length()     ; window_end++)
//         {
//             char_count[s[window_end] - 'A']++;
//             max_count = max(max_count, char_count[s[window_end] - 'A']);
            
//             while(window_end - window_start - max_count + 1 > k)
//             {
//                 char_count[s[window_end]- 'A']--;
//                 window_start++;
//             }
            
//             max_length = max(max_length, window_end - window_start + 1);
//         }
//         return max_length;
         
        int left = 0;
        vector<int> count(26,0);
        int max_char = INT_MIN;
        int maxVal = 0;
        for(int right = 0;right < s.size();right++)
        {
            int windowSize = right - left + 1;
            count[s[right] - 'A']++;
            max_char = max(max_char,count[s[right]-'A']);
            int  replacedCount = windowSize - max_char;
            if(replacedCount > k)
            {
                count[s[left] - 'A']--;
                left++;
            }
            else
                maxVal = max(maxVal,windowSize);
        }
        return maxVal;
    }
};