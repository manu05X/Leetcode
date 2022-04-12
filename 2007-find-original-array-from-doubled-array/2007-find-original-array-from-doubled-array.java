class Solution {
    public int[] findOriginalArray(int[] changed) {
        //checking edge condition of odd and zero length
        if(changed.length%2 != 0 || changed.length == 0)
            return new int[0];
        
        List<Integer> ans = new ArrayList();
        // Sorting the array
        Arrays.sort(changed);
        Queue<Integer> q = new LinkedList<Integer>();
        
        for(int i = 0; i < changed.length; i++)
        {
            // if queue is not empty and front of the queue is same as in changed array then pop/remove it from queue 
            if(!q.isEmpty() && changed[i] == q.peek()){
                q.poll();
            }
            else{// add the double of current element to the queue 
                q.add(changed[i]*2);
                ans.add(changed[i]); // add current element to answer array
                //idx++;
            }
        }
        // (ans.stream().mapToInt(i->i).toArray();) changing Integet to int in array
        return !q.isEmpty()?new int[0]: ans.stream().mapToInt(i->i).toArray();
    }
}