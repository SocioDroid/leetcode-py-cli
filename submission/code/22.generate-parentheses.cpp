class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string ans = "";
        vector<string> res;
        solve(n, ans, n, n, res);
        return res;
    }
    
    void solve(int n, string ans, int left, int right, vector<string>& res){
        if(ans.length() == n*2) {
            res.push_back(ans);
            return;
        }

        if(left > 0 && left <= right){
            ans += "(";
            solve(n, ans, left-1, right, res);
            ans.erase(ans.end() - 1);
        }
         if(right>0 && left < right){
            ans += ")";
            solve(n, ans, left, right-1, res);
            ans.erase(ans.end() - 1);
        }
    }
};