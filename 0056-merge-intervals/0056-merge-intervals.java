class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        List<int[]> ans = new ArrayList<>();

        if(n < 2){
            return intervals;
        }
    
        /*(a, b) -> Integer.compare(a[0], b[0]): This is a lambda expression representing a custom comparator. The lambda expression takes two parameters a and b, which are elements of the array intervals. It compares the first element of each interval (a[0] and b[0]) using Integer.compare(a[0], b[0]). This comparison is used to determine the sorting order
        */
         // Sort the intervals in increasing order
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        // Push the first interval into ans
        ans.add(intervals[0]);

        int j = 0;
        for(int i = 1; i < n;  i++)
        {//first element of interval < than 2nd element of ans vector so merge
            if(intervals[i][0] <= ans.get(j)[1])
            {// Change the ans second element by comparing interval's 2nd and ans 2nd element
                ans.get(j)[1] = Math.max(intervals[i][1], ans.get(j)[1]);
            }
            else
            {
                j++;
                ans.add(intervals[i]);
            }
        }
        // Convert the list to a 2D array
        return ans.toArray(new int[ans.size()][]);
    }
}