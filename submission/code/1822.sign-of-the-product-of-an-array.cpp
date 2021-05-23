class Solution {
public:
    int arraySign(vector<int>& nums) {
    int c = 0;
    for(int i=0; i<nums.size(); i++)
    {
     if(nums[i] < 0)
        c++;
     else if(!nums[i])
         return 0;
    }
    if(c%2)
        return -1;
    return 1;
    }
};