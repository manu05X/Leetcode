class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int low=0,high=nums.size()-1,mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;

            // if mid is not even
            if(mid%2 != 0)
            {
                // if mid-1 is equal to mid then low = mid+1 so single element is on right half
                if(nums[mid-1]==nums[mid])
                    low=mid+1;
                else // if mid-1 is equal to mid then high = mid-1 so single element is on left half
                {
                    high=mid-1;
                }
            }
            else // if mid is even
            {
                // if evenMid and (evenMid+1) are equal so single element is on right half
                if(nums[mid]==nums[mid+1])
                {
                    low=mid+1;
                }
                else // if evenMid and (evenMid+1) are not equal so single element is on left half
                {
                    high=mid-1;
                }
            }
        }
        return nums[low];
    }
};

/*
1,1,2,2,3,3,4,4,8,8
0,1,2,3,4,5,6,7,8,9

so as per above example odd index and (odd index-1) element will alwase be equal for valid array.
But if any element occour only single time as in below example even index and (even index-1) will be equal

1,1,2,3,3,4,4,8,8
0,1,2,3,4,5,6,7,8



1,1,2,2,3,3,4,8,8
0,1,2,3,4,5,6,7,8

*/