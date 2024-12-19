class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int count = 0;
        int prefixSum = 0;
        int indexSum = 0;

        for(int i = 0; i <n; i++){
            prefixSum += arr[i];
            indexSum += i;

            if(indexSum == prefixSum){
                count++;
            }
        }

        return count;
    }
};