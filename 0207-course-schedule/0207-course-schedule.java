class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
         // Your Code goes here
       ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
       int[] inDegree = new int[numCourses];
       
       for(int i = 0; i < numCourses; i++){
           adj.add(new ArrayList<>());
       }
       
       for(int[] pre : prerequisites){
           int u = pre[1];
           int v = pre[0];
           
           adj.get(u).add(v);  // Edge from u -> v
           inDegree[v]++;          // Increase indegree of v. v has incomming edge u --> v
       }
       
       Queue<Integer> q = new LinkedList<>();
       for(int i = 0; i < numCourses; i++){
           if(inDegree[i] == 0){
               q.add(i);
           }
       }
       
       int count = 0;
       while(!q.isEmpty()){
           int curr = q.poll();
           count++;
           
           for(int neighbor : adj.get(curr)){
               inDegree[neighbor]--;
               
               if(inDegree[neighbor] == 0){
                   q.add(neighbor);
               }
           }
       }
        
        
        return count == numCourses;
    }
}