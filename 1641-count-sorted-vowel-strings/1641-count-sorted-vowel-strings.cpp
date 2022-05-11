class Solution {
public:
    int countVowelStrings(int n) {
        int a=0;
        int e=0;
        int o=0;
        int i=0;
        int u=1;

        // from last to front, u to a 
        while(n!=0){
            i+=u;
            o+=i;
            e+=o;
            a+=e;
            n--;
        }

        int sum = a+e+i+o+u;
        return sum;
    }
};