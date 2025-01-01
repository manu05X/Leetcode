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

/*

Algorithm

Initialize ones = 0, zeros = 0, and best to a very small value like negative infinity.
Iterate i from 0 until s.length - 1:
If s[i] == '1', increment ones.
Otherwise, increment zeros.
Update best with zeros - ones if it is larger.
If the final character of s is equal to '1', increment ones.
Return best + ones.


*/