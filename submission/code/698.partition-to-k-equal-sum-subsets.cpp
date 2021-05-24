class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int req_sum = sum/k;
        
        // cout<<req_sum<<"  "<<*max_element(nums.begin(), nums.end());
        
        if(sum%k != 0 || *max_element(nums.begin(), nums.end()) > req_sum)
            return false;
        vector<bool> visited(nums.size(), false);
        return solve(nums, 0, k, 0, req_sum, visited);
    }
    
    bool solve(vector<int>& nums, int index,int  k,int curr_sum, int& req_sum, vector<bool>& visited){
        if(k == 0)
            return true;
        
        // cout<<"Req sum : "<<req_sum<<endl;
        if(req_sum == curr_sum)
            return solve(nums, 0, k-1, 0, req_sum, visited);
        
        for(int i=index; i<nums.size(); i++){
            if(!visited[i] && curr_sum+nums[i] <= req_sum){
                visited[i] = true;
                if(solve(nums, i+1, k, curr_sum + nums[i], req_sum, visited))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
};