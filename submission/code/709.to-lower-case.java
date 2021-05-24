class Solution {
    public String toLowerCase(String str) {
        char []arr = str.toCharArray();
        for(int i=0; i<arr.length;i++){
            char c = arr[i];
			if (c >= 'A' && c <= 'Z') {
				arr[i] = (char) (c + 32);
			}
        }
        return new String(arr);
    }
}