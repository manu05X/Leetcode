class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long int num1 = x;
        long int num2 = 0;
        while(num1){
            num2 = 10*num2 + num1%10;
            num1/=10;
        }
        return num2 == x;
    }
};