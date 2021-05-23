class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] arr = new int[nums.length];
        int mid = nums.length/2;
        int j = 0;
        for(int i=0; i<mid; i++){
            arr[j++] = nums[i];
            arr[j++] = nums[mid+i];
        }
        return arr;
    }
}