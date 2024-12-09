class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int n = sweetness.size();
        int lo = 1; // Minimum possible sweetness
        int hi = 0; // Maximum possible sweetness (sum of all elements)

        for(int i = 0; i < n; i++){
            hi += sweetness[i];
        }

        // Perform binary search
        while(lo <= hi){
            int mid = (lo+hi)/2;

            if(canFormPiece(sweetness,k, mid)){
                // If we can split with at least k+1 pieces and each piece >= mid
                lo = mid+1; // Try to increase the minimum sweetness
            } else {
                hi = mid-1; // Otherwise, decrease the minimum sweetness
            }
        }

        return hi; // The maximum minimum sweetness
    }

    bool canFormPiece(vector<int>& sweetness, int k, int minSweetness){
        int currSweetness = 0; // Current piece's total sweetness
        int pieces = 0; // Number of pieces formed

        for(int i = 0; i < sweetness.size(); i++){
            currSweetness += sweetness[i];

            if(currSweetness >= minSweetness){
                pieces++; // Form a piece
                currSweetness = 0; // Reset the sum for the next piece
            }
        }

        // We need at least k+1 pieces to satisfy the conditions
        return pieces >= k+1;
    }
};