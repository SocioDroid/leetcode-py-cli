class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back({});
        for(int i=0; i<nums.size(); i++){
            int size = res.size();
            for(int j=0; j<size ;j++){
                vector<int> v = res[j];
                v.push_back(nums[i]);
                res.push_back(v);   
            }
        }
        set<vector<int>> s(res.begin(), res.end());
        vector<vector<int>>res2(s.begin(), s.end());
        return res2;
    }
};