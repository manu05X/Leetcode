class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int one = 0;
        int zero = 0;

        int bestAns = INT_MIN;

        for(int i = 0; i < n-1; i++){
            if(s[i] == '1'){
                one++;
            } else {
                zero++;
            }

            bestAns = max(bestAns, zero-one);
        }


        if(s[n-1] == '1'){
            one++;
        }

        return bestAns+one;
    }
};