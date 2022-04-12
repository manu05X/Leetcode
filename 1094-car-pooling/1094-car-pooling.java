class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
         int[] currCapacity = new int[1001];
        
        int n = trips.length;
        
        for(int i = 0; i < n; i++){
            int passanger = trips[i][0];
            
            currCapacity[trips[i][1]] += passanger;
            currCapacity[trips[i][2]] -= passanger;
        }
        
        for(int x : currCapacity){
            if(x != 0){
                capacity -= x;
                if(capacity < 0)
                    return false;
            }
        }
        
        return true;
    }
}