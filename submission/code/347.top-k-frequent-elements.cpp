struct comp{
  bool operator()(const vector<int>& nums1, const vector<int>& nums2)
    {
        return nums1[1] > nums2[1];
    } 
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq_map;
        
        for(int i:nums)
            freq_map[i]+=1;
            
        // for(auto i=freq_map.begin(); i!=freq_map.end(); i++)
        //     cout<<"Key : "<<i->first<<"\tvalue : "<<i->second<<endl;
        priority_queue<vector<int>, vector<vector<int>>, comp> heap;
        
        for(auto i=freq_map.begin(); i!=freq_map.end(); i++)
        {
            if(heap.size() < k){
                heap.push({i->first, i->second});
            }else if(heap.top()[1] < i->second){
                heap.pop();
                heap.push({i->first, i->second});
            }
        }
        
        vector<int> v;
        // cout<<"size : "<<heap.size()<<endl;
        while(!heap.empty()){
            v.push_back(heap.top()[0]);
            // cout<<heap.top()[0]<<"\t"<<heap.top()[1]<<endl;
            heap.pop();
        }
        return v;
    }
};