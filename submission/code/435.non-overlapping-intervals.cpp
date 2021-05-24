class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() < 2)
            return 0;
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int left = 0;
        int right = 1;
        int n = intervals.size();
        while(right < n)
        {
            if(intervals[left][1] <= intervals[right][0]){
                left = right;
                right++;
            }
            else if(intervals[left][1] <= intervals[right][1])
            {
                count++;
                right++;
            }else if(intervals[left][1] > intervals[right][1])
            {
                count++;
                left = right;
                right+=1;
            }
               
        }
        return count;
    }
};