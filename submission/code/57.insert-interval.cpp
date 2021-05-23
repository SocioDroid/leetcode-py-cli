class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0) return {newInterval};
        auto compare = [] (const vector<int>&intv1, const vector<int>&intv2)
                          { return intv1[1] < intv2[0]; };
        auto range = equal_range(intervals.begin(), intervals.end(), newInterval, compare);
        auto itr1 = range.first, itr2 = range.second;
        if (itr1 == itr2) {
            intervals.insert(itr1, newInterval);
        } else {
            itr2--;
            *(itr2->begin()+0) = min(newInterval[0], *(itr1->begin()+0));
            *(itr2->begin()+1) = max(newInterval[1], *(itr2->begin()+1));
            intervals.erase(itr1, itr2);
        }
        return intervals;
        
    }
};