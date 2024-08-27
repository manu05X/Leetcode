class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        List<String> temp = new ArrayList<>();

        dfs(0, s, res, temp);

        return res;
    }

    void dfs(int idx, String s, List<List<String>> res, List<String> temp)
    {
        if(idx == s.length())
        {
            res.add(new ArrayList<>(temp));
            return;
        }

        for(int i = idx; i < s.length(); i++)
        {
            if(isPalindrom(s,idx,i))
            {
                temp.add(s.substring(idx, i+1));
                dfs(i+1, s, res,temp);
                temp.remove(temp.size()-1);
            }
        }
    }

    boolean isPalindrom(String s, int start, int end)
    {
        while(start <= end)
        {
            if(s.charAt(start) != s.charAt(end))
                return false;
            
            start++;
            end--;
        }
        return true;
    }
}