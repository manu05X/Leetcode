class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return 0;  // No non-leaf nodes if less than 2 leaves
        if (n == 2) return arr[0] * arr[1];  // Only one possible product
        
        int sum = 0;
        vector<int> temp = arr;
        
        while (temp.size() > 1) {
            int min_product = INT_MAX;
            int min_index = -1;
            
            // Find the pair of adjacent elements with smallest product
            for (int i = 0; i < temp.size() - 1; i++) {
                int product = temp[i] * temp[i+1];
                if (product < min_product) {
                    min_product = product;
                    min_index = temp[i] < temp[i+1] ? i : i+1;
                }
            }
            
            sum += min_product;
            
            // Remove the smaller element of the pair
            temp.erase(temp.begin() + min_index);
        }
        
        return sum;
    }
};