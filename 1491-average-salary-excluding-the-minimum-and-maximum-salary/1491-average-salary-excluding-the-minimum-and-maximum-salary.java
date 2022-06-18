class Solution {
    public double average(int[] salary) {
        if(salary.length < 1)
            return 0D;
        
        int maxE = Integer.MIN_VALUE;
        int minE = Integer.MAX_VALUE;
        
        int ans = 0;
        for(int i = 0; i < salary.length; i++)
        {
            maxE = Math.max(maxE, salary[i]);
            minE = Math.min(minE, salary[i]);
            
            ans += salary[i];
        }
        ans = (ans-(maxE+minE));
        int n = salary.length - 2;
        return (double)ans/n;
    }
}