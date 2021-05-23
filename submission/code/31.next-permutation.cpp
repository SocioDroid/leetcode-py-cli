class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)
            return;
        int i = n-1;
        
        while(i>0 && nums[i] <= nums[i-1])
            i--;
        
        i--;
        cout<<i<<endl;
        if(i == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int ti = i+1;
        int tempidx = -1;
        int mindiff = INT_MAX;
        
        while(ti<n && nums[i] < nums[ti] && nums[ti]-nums[i] <= mindiff){
            mindiff = nums[ti]-nums[i];
            tempidx = ti;
            ti++;
        }
        swap(nums[i], nums[tempidx]);
        
        reverse(nums.begin()+i+1, nums.end());
        return;
    }
};