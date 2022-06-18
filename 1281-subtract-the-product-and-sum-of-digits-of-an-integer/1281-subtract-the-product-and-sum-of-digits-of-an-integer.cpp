class Solution {
public:
    int subtractProductAndSum(int n) {
        int d = 0;
        int sum = 0;
        int pro = 1;
        
        while(n != 0)
        {
            d = n%10;
            n/=10;
            sum += d;
            pro = pro*d;
        }
        
        return (pro-sum);
    }
};