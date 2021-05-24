class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        // set<char> char_set;
        // char_set.insert(s[0]);
        // int res_max=0;
        // for(int i=1; i<s.length(); i++)
        // {
        //     if(char_set.find(s[i]) == char_set.end())
        //     {
        //         char_set.insert(s[i]);
        //         res_max = max((int)char_set.size(), res_max);
        //     }
        //     else
        //     {
        //         char_set.erase(char_set.find(s[i]));
        //         // char_set.insert(s[i]);
        //         cout<<char_set.size();
        //     }
        // }
        // res_max = max((int)char_set.size(), res_max);
        // cout<<char_set.size();
        // char_set.clear();
        // return res_max;
        unordered_set<char> set;
    
		int i = 0, j = 0, n = s.size(), ans = 0;
    
		while( i<n && j<n)
		{
			if(set.find(s[j]) == set.end()) //If the character does not in the set
			{
				set.insert(s[j++]); //Insert the character in set and update the j counter
				ans = max(ans, j-i); //Check if the new distance is longer than the current answer
			}
			else
			{
				set.erase(s[i++]); 
				/*If character does exist in the set, ie. it is a repeated character, 
				we update the left side counter i, and continue with the checking for substring. */
			}
		}
    
		return ans;
    }
};