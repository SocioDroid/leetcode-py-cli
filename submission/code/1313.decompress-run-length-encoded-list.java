class Solution {
    public int[] decompressRLElist(int[] nums) {
        ArrayList<Integer>  list = new ArrayList<Integer>();
        for(int i=1;i<nums.length; i+=2){
            for(int j=0; j<nums[i-1]; j++)
                list.add(nums[i]);
        }
        int [] result = new int[list.size()];
        for(int i=0; i<list.size(); i++){
            result[i] = list.get(i);
        }
        return result;
    }
}