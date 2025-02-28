class Solution {
    public int fib(int n) {
         if(n <= 1){
            return n;
        }
        
        int prevStep = 0;
        int currStep = 1;
        
        for(int i = 2; i <= n; i++){
            int nextStep = currStep + prevStep;
            
            prevStep = currStep;
            currStep = nextStep;
        }
        
        return currStep;
    }
}