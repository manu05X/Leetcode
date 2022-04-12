/*
For any time x, we can have total trips = sum(int(x / t)) where t denotes time[i] for i in range 0 to len(times) - 1.
We need to find minimum x.
We can use a binary search approach.
During the contest I got away with keeping lo = 1 and hi = 10 ^ 15
On further inspection of the problem we can deduce that max value of x can be min(times) * totalTrips . So that can be used as hi
*/
class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        long h = 100000000000000L; //maximum bound = min(time) * totalTrips , time[i], totalTrips <= 107 = 10^14
        long l = 0;
        long ans = 0;
        
        while(l<h){
            long mid = l + (h - l)/2;
            long sum = 0;
            
            //we can have total trips = sum(int(x / t)) where t denotes time[i] for i in range 0 to len(times) - 1.
            for(int t : time){
                sum += (mid/t);
            }
            
            if(sum < totalTrips){
                l = mid + 1;
                ans = mid+1;
            }else{
                h = mid;
                ans = mid;
            }
        }
        return ans;
    }
}