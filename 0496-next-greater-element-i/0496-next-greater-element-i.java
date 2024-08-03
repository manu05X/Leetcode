class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Deque<Integer> st = new ArrayDeque<>();
        Map<Integer, Integer> mp = new HashMap<>();

        for(int x : nums2)
        {
            while(!st.isEmpty() && st.peek() < x){
                mp.put(st.pop(), x);
            }

            st.push(x);
        }

        int n = nums1.length;
        int[] ans = new int[n];
        for(int i = 0; i < n; i++){
            ans[i] = mp.getOrDefault(nums1[i],-1);
        }

        return ans;
    }
}