class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i] < nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
            }
            else
            {
                v.push_back(nums2[j]);
                j++;
            }
        }
        if(i<nums1.size())
            v.insert(v.end(), nums1.begin()+i, nums1.end());
        else if(j<nums2.size())
            v.insert(v.end(), nums2.begin()+j, nums2.end());
        for(int i:v)
            cout<<i;
        // return 0;
        if(v.size()%2)
            return v[v.size()/2];
        return (v[v.size()/2] + v[(v.size()/2)-1])/2.0;   
    }
};