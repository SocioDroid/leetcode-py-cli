class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end=nums.size()-1;
        int mid;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[start] <= nums[mid])
            {
                if(nums[start] <= target && nums[mid]>= target)
                    end = mid-1;
                else
                    start = mid+1;
            
            }
            else
            {
                if(nums[mid] <= target && nums[end]>= target)
                    start = mid+1;
                else
                    end = mid-1;
            
            }
        }
        return -1;
    }
};