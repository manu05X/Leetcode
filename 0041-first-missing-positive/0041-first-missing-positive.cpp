class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int len = A.size();
        for(int i=0; i<len; i++) {
            // Start assigning the numbers from 1 to len with their respective positions.
            // We can ignore the numbers that doesn't lie in range of [1,len]
            // 3rd condition is used to prevent the case for infinite for loop
            // element at the index nums[i] - 1 should not be nums[i] itself).
            if(A[i] >0 && A[i] <= len &&  A[A[i]-1]!= A[i]) { 
                swap(A[A[i]-1], A[i]);
                i--;
            }
        }
        // Since in the above for loop we have assigned the numbers w.r.t positions
        for(int i=0; i<len; i++){
            // Once the number is not equal to its position, we can return that position
            if(A[i]!=i+1) return i+1; 
        }
        // If we were able to get every number in that range, then we can return len+1.
        return len+1;
    }
};