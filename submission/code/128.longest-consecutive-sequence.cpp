class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        set<int> s(nums.begin(), nums.end());

        
        map<int, int> u_map;
        
        for(auto i : s){
            u_map[i] = i;
        }
        
        for(auto i : s){
            if(u_map.find(i-1) != u_map.end())
                u_map[i] = find(u_map,i-1);
            else
                u_map[i] = i;
        }
        map<int, int> count;
        int max_x = INT_MIN;
        for(auto m : u_map){
            max_x = max(max_x, ++count[m.second]);
        }
        
        return max_x;
    }
    
    int find(map<int, int>& u_map, int x){
        if(u_map[x] != x)
            u_map[x] = find(u_map, u_map[x]);
        return u_map[x];
    }
};


