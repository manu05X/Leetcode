class Solution {
public:
    string longestPalindrome(string s) {
        string s_prime = "#";
        for (char c : s) {
            s_prime += c;
            s_prime += "#";
        }

        int n = s_prime.length();
        vector<int> palindrome_radii(n, 0);
        int center = 0;
        int radius = 0;

        for (int i = 0; i < n; i++) {
            int mirror = 2 * center - i;

            if (i < radius) {
                palindrome_radii[i] = min(radius - i, palindrome_radii[mirror]);
            }

            while (i + 1 + palindrome_radii[i] < n &&
                   i - 1 - palindrome_radii[i] >= 0 &&
                   s_prime[i + 1 + palindrome_radii[i]] ==
                       s_prime[i - 1 - palindrome_radii[i]]) {
                palindrome_radii[i]++;
            }

            if (i + palindrome_radii[i] > radius) {
                center = i;
                radius = i + palindrome_radii[i];
            }
        }

        int max_length = 0;
        int center_index = 0;
        for (int i = 0; i < n; i++) {
            if (palindrome_radii[i] > max_length) {
                max_length = palindrome_radii[i];
                center_index = i;
            }
        }

        int start_index = (center_index - max_length) / 2;
        string longest_palindrome = s.substr(start_index, max_length);

        return longest_palindrome;
    }
};


/*
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

        // Initializing start and end indexes of resultant substring as zero
	    int start = 0, end = 0;

        for(int i = 0; i < n; i++){
            int len1 = isPalindrome(s,i,i); // try for odd length
            int len2 = isPalindrome(s,i,i+1); // try for even length

            //Now we have both half length len1 and len2 so we now calculate the max length of both
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
*/