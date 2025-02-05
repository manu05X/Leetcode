class Solution {
    public int maxWidthRamp(int[] nums) {
        int n = nums.length;
        Stack<Integer> st = new Stack<>();

        for(int i = 0; i < n; i++){
            if(st.isEmpty() || nums[st.peek()] > nums[i]){
                st.push(i);
            }
        }

        int maxWidth = 0;

        for(int j = n-1; j >= 0; j--){
            while(!st.isEmpty() && nums[st.peek()] <= nums[j]){
                maxWidth = Math.max(maxWidth, j-st.peek());
                st.pop();
            }
        }

        return maxWidth;
    }
}
/*
[6,0,8,2,1,5]

6,0


0,1,5

1,


[9,8,1,0,1,9,4,0,4,1]

9,8,1,0


 */