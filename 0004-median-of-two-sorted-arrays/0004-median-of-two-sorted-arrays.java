class Solution {
    public double findMedianSortedArrays(int[] a, int[] b) {
        // DO NOT MODIFY BOTH THE LISTS
    // we have two arrays, we have to make sure 1st array is smaller
        // now this problem can be done using, Merge function of merge sort in TC-> O(N+M)

        // but we need TC of log
        // so, here we are dividing two array in two parts mid1, mid2,
        // if we have n = 4 , m = 6 then n+m = 10,
        // mid of of n+m is 5, which is half, now we need combination of both array with 5 elements
        // but we want to reduce search space
        // it can be 1+4, 2+3, 0+5,
        // but we need to choose those element from A  whose max is <= non choosen part of B  means min of B
       
        // keeping in mid array is sorted
        // A  -> 7 12 14 15
        // B  -> 1 2 3 4 9 11
        // C  -> 1 2 3 4 7 9 11 12 14 15
       
        // now we can choose    
       
        // 1st
        // A  -> 7 12 |(cut1) 14 15
        // B  -> 1 2 3 |(cut2) 4 9 11

        // from A   7 12(L1)     (R1) 14 15
        // from B   1 2 3(L2)    (R2) 4 9 11
        // L1,L2, will be max of left half and R1,R2 will be min in right half

        // now C -> 1 2 3 7 12 14 15 4 9 11 but this not in correct order,

        // so,
        //     from A   7 12(L1) --->\  /--> (R1) 14 15
        //                                               \/
        //                                               /\
        //     from B   1 2 3(L2)  -->/  \---> (R2) 4 9 11

        // 2ND
        // A  -> |(cut1) 7 12 14 15
        // B  -> 1 2 3 4 9 |(cut2) 11

        // from A   intMin(L1)       (R1)7 12 14 15
        // from B   1 2 3 4 9(L2)    (R2)11

        // so,
        //     from A   -INFINITY(L1) --->\  /--> (R1) 7 12 14 15
        //                                                          \/
        //                                                          /\
        //     from B   1 2 3 4 9(L2)      -->/  \---> (R2)11
       
        // 3RD
        // A  -> 7 |(cut1) 12 14 15
        // B  -> 1 2 3 4 |(cut2) 9 11

        // from A   7(L1)       (R1)12 14 15
        // from B   1 2 3 4(L2)    (R2)9 11

        // so,
        //     from A   7(L1)             --->\  /--> (R1)12 14 15
        //                                                     \/
        //                                                     /\
        //     from B   1 2 3 4 (L2)   -->/  \---> (R2)9 11

   
        // if (L1 <= R2 && L2 <= R1)
        // {
        //     then we can our left half j=have elements,
        //     we just find max of (L1, L2,) + min of(R1, R2)/2 for even n+M
        //     for odd we say max of(L1, L2)
        // }
        // but if (L1 > R2)
        //     then we know it is greater, it should be at right half
        //     so we decrease high = cut1 - 1
        // but if (L2 > R1)
        //     then we increase low = cut1 + 1
       
        // we do this until low <= high or l1<= r2, l2 <= r1
        // try dry running with table of low, high, cut1, cut2, l1, l2, r1,r2 it will be easy to understand

        // TC -> O(M+N) SC -> O(1)
        int n = a.length;
        int m = b.length;

        if(n > m)
            return findMedianSortedArrays(b, a);
       
        int low = 0, high = n;
       
        while(low <= high)
        {
            int cut1 = low + (high-low)/2;
            int cut2 = (n + m + 1)/2 - cut1;
           
            int left1 = (cut1 == 0) ? Integer.MIN_VALUE : a[cut1-1];
            int left2 = (cut2 == 0) ? Integer.MIN_VALUE : b[cut2-1];

            int right1 = (cut1 == n) ? Integer.MAX_VALUE : a[cut1];
            int right2 = (cut2 == m) ? Integer.MAX_VALUE : b[cut2];

            if(left1 <= right2 && left2 <= right1)
            {
                if((n+m)%2 == 0)
                    return (Math.max(left1, left2) + Math.min(right1, right2)) /2.0 ;
                else
                    return (Math.max(left1, left2));
            }
            if(left1 > right2)
            {
                high = cut1 - 1;
            }
            if(left2 > right1)
            {
                low = cut1 + 1;
            }
        }
        return 0.0;    
    }
}