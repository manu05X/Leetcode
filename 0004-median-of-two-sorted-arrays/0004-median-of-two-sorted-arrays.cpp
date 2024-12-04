class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(n  > m){
            return findMedianSortedArrays(nums2, nums1);
        }

        int l = 0;
        int h = n;

        int leftHalf = (n+m+1)/2;

        int totalLeng = n+m;

        while(l <= h){
            int mid1 = (l+h)/2;
            int mid2 = leftHalf-mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1 < n){
                r1 = nums1[mid1];
            }

            if(mid2 < m){
                r2 = nums2[mid2];
            }

            if(mid1-1 >= 0){
                l1 = nums1[mid1-1];
            }

            if(mid2-1 >= 0){
                l2 = nums2[mid2-1];
            }



            if(l1 <= r2 && l2 <= r1){
                if(totalLeng % 2 == 1){
                    return max(l1,l2);
                }

                return ((double)(max(l1,l2) + min(r1,r2))) / 2.0;
            }
            else if(l1 > r2){
                h = mid1 - 1;
            } else {
                l = mid1+1;
            }

        }

        return 0;
    }
};