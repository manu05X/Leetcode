class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        int n = weight.size();

        sort(weight.begin(), weight.end());
        int ans = 0;
        int runningSum = 0;

        for(auto x : weight){
            runningSum += x;

            if(runningSum <= 5000){
                ans++;
            }
        }

        return ans;
    }
};