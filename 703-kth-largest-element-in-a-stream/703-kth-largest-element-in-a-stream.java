/*

Here is my understanding,
Given [4, 5, 8, 2] , k = 3 ---> before adding the numbers lets calculate below,
Elements in sorted order --> 2, 4, 5, 8 ( in this array 1st largest element is 8, 2nd largest element is 5 and 3rd largest element is 4 and so on)

Now let us,

add(3) to stream --> stream becomes [4, 5, 8, 2, 3] --> sorted order [2, 3, 4, 5, 8] (1st largest element is 8, 2nd largest element is 5 and 3rd largest element is 4 and so on) -- return 3rd largest which is 4.
add(5) to stream --> stream becomes [4, 5, 8, 2, 3, 5] --> sorted order [2, 3, 4, 5, 5, 8] (1st largest element is 8, 2nd largest element is 5 and 3rd largest element is 5 and so on) -- return 3rd largest which is 5.
add(10) to stream --> stream becomes [4, 5, 8, 2, 3, 5, 10] --> sorted order [2, 3, 4, 5, 5, 8, 10] (1st largest element is 10, 2nd largest element is 8 and 3rd largest element is 5 and so on) -- return 3rd largest which is 5.
add(9) to stream --> stream becomes [4, 5, 8, 2, 3, 5, 10, 9] --> sorted order [2, 3, 4, 5, 5, 8, 9, 10] (1st largest element is 10, 2nd largest element is 9 and 3rd largest element is 8 and so on) -- return 3rd largest which is 8.
add(4) to stream --> stream becomes [4, 5, 8, 2, 3, 5, 10, 9, 4] --> sorted order [2, 3, 4, 4, 5, 5, 8, 9, 10] (1st largest element is 10, 2nd largest element is 9 and 3rd largest element is 8 and so on) -- return 3rd largest which is 8.

*/
class KthLargest {
    PriorityQueue<Integer> pq;
    int k = 0;
    public KthLargest(int k, int[] nums) {
        this.k = k;
        pq = new PriorityQueue<>();
        for(int i : nums)
            this.add(i);
        
    }
    
    public int add(int val) {
        pq.add(val);
        if(pq.size()>k){
            pq.remove();
        }
        return pq.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */