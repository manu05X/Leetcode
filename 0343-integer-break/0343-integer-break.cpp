class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3){
            return n-1;
        }

        // if divisible by 3
        if(n%3 == 0){
            int x = pow(3,n/3);
            return x;
        }
        // if not divisible by 3
        if(n%3 == 1){
            int x = pow(3,n/3-1)*4;
            return x;
        }

        return pow(3,n/3)*2;
    }
};