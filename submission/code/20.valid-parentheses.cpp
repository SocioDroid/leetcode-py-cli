class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                v.push_back(s[i]);
            else if(v.size())
            {
                if(s[i] == ')' && v.back() == '(')
                    v.pop_back();
                else if(s[i] == '}' && v.back() == '{')
                    v.pop_back();
                else if(s[i] == ']' && v.back() == '[')
                    v.pop_back();
                else
                    return false;
            }
            else
                return false;
        }
        return v.size() ? false : true;
    }
};