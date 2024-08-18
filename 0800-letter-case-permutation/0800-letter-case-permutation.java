class Solution {
    public char[] charArray;
    public List<String> ans = new ArrayList<>();

    public List<String> letterCasePermutation(String s) {
        charArray = s.toCharArray();
        dfs(0);

        return ans;
    }

    public void dfs(int idx){
        if(idx >= charArray.length){
            ans.add(new String(charArray));
            return;
        }

        dfs(idx+1);

        if(Character.isLetter(charArray[idx])){
            charArray[idx] ^= ' ';
            dfs(idx+1);
            charArray[idx] ^= ' ';
        }
    }
}