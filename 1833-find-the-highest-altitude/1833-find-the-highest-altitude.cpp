class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = INT_MIN;
        int n = gain.size();
        int temp = 0;

        for(int i = 0; i < n; i++){
            // Update the current altitude
            temp += gain[i];
            // Update the answer to store the maximum altitude
            ans = max(ans, temp);
        }

        return ans< 0 ? 0 : ans;
    }
};