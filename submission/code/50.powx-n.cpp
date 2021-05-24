class Solution {
public:
    double myPow(double x, int n) {
        if(x==1)
            return 1;
        
        double ans = 1;
        for(int i=abs(n); i>0; i=i/2)
        {
            if(i%2)
                ans *= x; 
            x*=x;
        }
            
        if(n<0)
              return 1/ans;
        return ans;
    }
};