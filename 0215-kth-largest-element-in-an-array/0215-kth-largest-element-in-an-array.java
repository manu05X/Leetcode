class Solution {
    public int findKthLargest(int[] nums, int k) {

        // Creating a min-Heap by default (minPq) which stores the k largest elements.
        PriorityQueue<Integer> minPq = new PriorityQueue<Integer>();

        // Traverse each number in the array
        for (int num : nums) {
            minPq.add(num); // Add the current number to the heap

            // If the heap size exceeds k, remove the smallest element
            if (minPq.size() > k) {
                minPq.poll();
            }
        }

        // The k-th largest element will be at the top of the heap
        return minPq.peek();
    }
}


/*

2
-

2
3
-

1
2
3

2
3
-

2
3
5

2
3
5
-

2
3
5

3
5
-

3
5
6

5
6
-

4
5
6

5
6
-


5
6

*/


/*
class Solution {
    public int findKthLargest(int[] nums, int k) {
        // Create a min-heap (PriorityQueue with natural ordering, i.e., min-heap)
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        // Iterate through the elements of the array
        for (int num : nums) {
            // Add element to the min-heap if its size is less than k
            if (minHeap.size() < k) {
                minHeap.add(num);
            } else {
                // Replace root with current element if it's greater than the root
                if (num > minHeap.peek()) {
                    minHeap.poll(); // Remove the root (smallest element)
                    minHeap.add(num); // Add the current element
                }
            }
        }
        
        // The root of the min-heap will be the k-th largest element
        return minHeap.peek();
    }
}

*/