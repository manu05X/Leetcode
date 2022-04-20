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