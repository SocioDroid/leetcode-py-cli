class Solution {
public:
    int dp[100000];
    int solve(vector<vector<int> > &a, int i){
        if(i>=a.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        // don't take current
        int ans = solve(a,i+1);
        
        // take current and search for a job which starts after current ends
        
        // find the closent job which starts after the current ends
        int s = i, e= a.size()-1;
        int idx = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(a[mid][0]<a[i][1]) s = mid+1;
            else{
                idx = mid;
                e=mid-1;
            }
        }
        
        // there is no job after the current ends
        if(idx==-1) ans = max(ans, a[i][2]);
        
        
        else ans = max(ans, a[i][2] + solve(a,idx));
        
        return dp[i]= ans;
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& profit) {
        vector<vector<int> > a;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<s.size();i++){
            a.push_back({s[i],e[i],profit[i]});
        }
        sort(a.begin(),a.end());
        return solve(a,0);
    }
};