class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int res = 1;
        int flag = 0;
        vector<int> v;
        
        for(int i=0; i<nums.size(); i++){
            if(!nums[i])
                flag++;
            else
                res *= nums[i];
        }
        
        if(flag>1)
        {
            for(int i=0; i<nums.size(); i++)
                v.push_back(0);
        }
        
        else if(flag)
        {
            for(int i=0; i<nums.size(); i++){
                if(!nums[i])
                    v.push_back(res);
                else
                    v.push_back(0);
            }
        }
        
        else
        {
            for(int i=0; i<nums.size(); i++)
                v.push_back(res / nums[i]);
        }
        return v;
    }
};