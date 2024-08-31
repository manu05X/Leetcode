class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int n = people.length;
        int lo = 0;
        int hi = n-1;

        Arrays.sort(people);
        int boat = 0;

        while(lo <= hi){
            int currWeight = people[lo]+people[hi];

            if(currWeight <= limit){
                lo++;
            }
    
            hi--;
            boat++;
        }

        return boat;
    }
}

/*
[3,2,2,1], limit = 3

[1,2,2,3]



*/