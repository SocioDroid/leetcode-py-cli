class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int [] res = new int[nums.length];
        for(int i = 0; i < nums.length; i++){
            for(int j: nums){
                if(j<nums[i]){
                    res[i]++;
                }
            }
        }
        return res;
    }
}