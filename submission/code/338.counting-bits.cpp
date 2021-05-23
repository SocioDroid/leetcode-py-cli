class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0)
            return {0};
        vector<int> v(num+1, 0);
        v[0] = 0;
        v[1] = 1;
        for(int i=1; i<=num; i++)  
        {
            if(i%2)
                v[i] = v[i>>1] + 1;
            else
                v[i] = v[i>>1];
        }
        return v;
    }
};