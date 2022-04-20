class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        // Sort the array boxTypes in decreasing order of a number of units.
        Arrays.sort(boxTypes, (a,b)->b[1]-a[1]);
        
        int unitCount = 0;
        for(int[] box : boxTypes)
        {
            // min of truckSize ans box[0]
            int boxCount = Math.min(truckSize, box[0]);
            unitCount += boxCount * box[1];
            
            truckSize -= boxCount; //decrease the box by boxCount selected above
            // edge condition of truckSize
            if(truckSize == 0)
                break;
        }
        
        return unitCount;
    }
}

/*<------------------------------------Using Priority Queue--------------------------------------------------------->*/

class Solution {
public
    int maximumUnits(int[][] boxTypes, int truckSize) 
    {
        PriorityQueue<int[]> queue = new PriorityQueue<>((a, b)->b[1] - a[1]);
        queue.addAll(Arrays.asList(boxTypes));
        int unitCount = 0;
        while (!queue.isEmpty()) 
        {
            int[] top = queue.poll();
            int boxCount = Math.min(truckSize, top[0]);
            
            unitCount += boxCount * top[1];
            truckSize -= boxCount;
            
            if(truckSize == 0)
                break;
        }
        return unitCount;
    }
}
