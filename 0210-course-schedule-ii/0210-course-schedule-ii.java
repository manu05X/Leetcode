class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
         // Step 1: Build the graph and indegree array
       ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
       int[] inDegree = new int[numCourses];
       
       for(int i = 0; i < numCourses; i++){
           adj.add(new ArrayList<>());
       }
       
       // Populate the adjacency list and indegree array
       for(int[] pre : prerequisites){
           int u = pre[1];  // prerequisite task
            int v = pre[0];  // dependent task

            adj.get(u).add(v);  // Edge from u -> v
            inDegree[v]++;          // Increase indegree of v v has incomming edge u --> v
       }
       
        // Step 2: Initialize the queue with nodes having indegree 0
       Queue<Integer> q = new LinkedList<>();
       for(int i = 0; i < numCourses; i++){
           if(inDegree[i] == 0){
               q.add(i);
           }
       }
       
       // Step 3: Process the queue and perform topological sort
       int count = 0;
       int[] ans = new int[numCourses];
       while(!q.isEmpty()){
           int curr = q.poll();
           ans[count] = curr;
           count++;
           
           // Visit all the neighbors of the node
           for(int neighbor : adj.get(curr)){
               inDegree[neighbor]--;
               
               if(inDegree[neighbor] == 0){
                   q.add(neighbor);
               }
           }
       }

       if(count != numCourses){
        return new int[0];
       }
       // Step 4: If all tasks are processed, return true, else false
       return ans;
    }
}