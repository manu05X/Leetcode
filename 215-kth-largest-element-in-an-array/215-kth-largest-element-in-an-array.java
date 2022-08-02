class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> hp = new PriorityQueue<Integer>();
        
        for(int n : nums){
            hp.add(n);
            
            if(hp.size() > k)
                hp.poll();
        }
        return hp.poll();
    }
}