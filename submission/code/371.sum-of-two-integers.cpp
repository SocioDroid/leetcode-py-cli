class Solution {
public:
    int getSum(int a, int b) {
        int carry;
        while(b)
        {
            carry = (uint32_t)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};