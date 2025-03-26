class Solution {
    public int compress(char[] chars) {
        int writeIndex = 0;
        int left = 0;
        
        while (left < chars.length) {
            int right = left;
            while (right < chars.length && chars[right] == chars[left]) {
                right++;
            }
            
            chars[writeIndex++] = chars[left];
            int count = right - left;
            
            if (count > 1) {
                for (char c : Integer.toString(count).toCharArray()) {
                    chars[writeIndex++] = c;
                }
            }
            
            left = right;
        }
        
        return writeIndex;
    }
};