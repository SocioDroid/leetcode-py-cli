class Solution {
public:
    int mySqrt(int x) {
        if(!x)
            return 0;
        if(x == 1)
            return 1;
        if(x == 2)
            return 1;   
        
        long i = 1;
        long j = x;
        long long square, mid;
        while(i<j)
        {
            mid = (i+j)/2;
            square = mid * mid;
            if(square == x)
                return mid;
            else if(square > x)
                j = mid;
            else if(square < x)
                i = mid + 1;
        }
        return i-1;
    }
};