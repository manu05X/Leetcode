class Solution {
public:

    int isPalindrome(string& s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if (s.empty())
		    return "";

        // Initializing start and end indexes of resultant substring
	// as zero
	    int start = 0, end = 0;

        for(int i = 0; i < n; i++){
            int len1 = isPalindrome(s,i,i); // for odd length
            int len2 = isPalindrome(s,i,i+1); // for even length

            int len = max(len1,len2);

            if(len > end-start){
                // Updating start and end indexes of palindromic substring
			start = i - (len - 1) / 2;
			end = i + len / 2;
            }
        }

        return s.substr(start, end+1-start);
    }
};