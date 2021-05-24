class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3)
            return 0;
        
        vector<int> lmax(height.size());
        vector<int> rmax(height.size());
        
        lmax[0] = height[0];
        rmax[height.size()-1] = height.back();
        
        for(int i=1, j=height.size()-2; i<height.size(); i++, j--)
        {
            lmax[i] = max(lmax[i-1], height[i]);
            rmax[j] = max(rmax[j+1], height[j]);
        }
        
        int sum = 0;
        for(int i=1; i<height.size(); i++)
        {
            sum += min(lmax[i],rmax[i])-height[i];
        }
        return sum;
    }
};