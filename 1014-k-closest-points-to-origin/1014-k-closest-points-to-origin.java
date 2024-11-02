class Solution {
    public int[][] kClosest(int[][] points, int k) {
        // Sort the array with a custom lambda comparator function
        Arrays.sort(points, (a, b) -> squaredDistance(a) - squaredDistance(b));
        
        // Return the first k elements of the sorted array
        return Arrays.copyOf(points, k);
    }
    
    private int squaredDistance(int[] point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};


/*
class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> maxHeap = new PriorityQueue<int[]>((a,b) -> (a[0]*a[0] + a[1]*a[1]) - (b[0]*b[0] + b[1]*b[1]));

        int[][] ans = new int[k][2];

        for(int i = 0; i < points.length; i++){
            maxHeap.offer(points[i]);
        }

        for(int i = 0; i < k; i++){
            ans[i] = maxHeap.poll();
        }

        return ans;
    }
}
*/