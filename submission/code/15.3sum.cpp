class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3)
            return res;
        
        sort(nums.begin(), nums.end());
        
        if(nums[0] > 0)
            return res;    
        
        
        for(int k=0; k<nums.size(); k++)
        {
            int i=k+1, j=nums.size()-1;
            
            if(k>0 && nums[k] == nums[k-1] )
                continue;
                
            
            while(i<j)
            { 
                int temp = nums[i] + nums[j] + nums[k];
                if(!temp)
                {
                    res.push_back({nums[k], nums[i], nums[j]});
                    i++;
                    while(i<j && nums[i] == nums[i-1])
                        i++;
                    // while(i<j && nums[j] == nums[j+1])
                    //     j--;
                }    
                else if(temp > 0)
                    j--;
                else
                    i++;
            }
        }
        return res;
    }
};