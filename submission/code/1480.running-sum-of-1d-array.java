class Solution {
    public int[] runningSum(int[] nums) {
        int[] arr = new int[nums.length];
        for(int i=0; i<nums.length;i++){
            int sum = 0;
            for(int j=0; j<=i; j++){
                sum += nums[j];
            }
            arr[i] = sum;
        }
        return arr;
    }
}