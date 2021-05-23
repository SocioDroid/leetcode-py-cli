class Solution {
    public int subtractProductAndSum(int n) {
        int sum = 0;
        int product = 1;
        int temp;
        while(n != 0){
            temp = n % 10;
            sum += temp;
            product *= temp;
            n /= 10;
        }
        return product - sum;
    }
}