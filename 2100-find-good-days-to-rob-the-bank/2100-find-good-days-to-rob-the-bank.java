class Solution {
    public List<Integer> goodDaysToRobBank(int[] sec, int time) {
        int n = sec.length;
        
        int pre[] = new int[sec.length];
        int suf[] = new int[sec.length];
        
        for(int i = 1; i < n; i++)
        {
            if(sec[i] <= sec[i-1])
            {
                pre[i] = pre[i-1]+1;
            }
            else
            {
                pre[i] = 0;
            }
        }
        
        for(int i = n-2; i >= 0; i--)
        {
            if(sec[i] <= sec[i+1])
            {
                suf[i] = suf[i+1]+1;
            }
            else
            {
                suf[i] = 0;
            }
        }
        
        ArrayList<Integer> res = new ArrayList<>();
        for(int i = 0; i < n; i++)
        {
            if(time <= pre[i] && time <= suf[i])
                res.add(i);
        }
        
        return res;
    }
}