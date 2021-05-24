class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 0;
        int sk = 1;
        while(n)
        {
            c++;
            n &= (n-1);
        }
        return c;
    }
};