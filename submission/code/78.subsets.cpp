class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
        return res;
    }
};