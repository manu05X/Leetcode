class Solution {
public:
    // returns size of the current/latest palindrome
int ReturnPalindromeLength(string& s, int left, int right) {
	while (left >= 0 && right < s.length() && s[left] == s[right]) {
		left--;
		right++;
	}
	return right - left - 1;
}

string longestPalindrome(string s) {
	// Return an empty string if the original string itself
	// is empty or null
	if (s.empty())
		return "";

	// Initializing start and end indexes of resultant substring
	// as zero
	int start = 0, end = 0;

	for (int i = 0; i < s.length(); i++) {
		int len1 = ReturnPalindromeLength(s, i, i); // for odd length
		int len2 = ReturnPalindromeLength(s, i, i + 1); // for even length
		int len = max(len1, len2);

		if (len > end - start) {
			// Updating start and end indexes of palindromic substring
			start = i - (len - 1) / 2;
			end = i + len / 2;
		}
	}

	// Returning the longest palindromic substring
	return s.substr(start, end + 1 - start);
}
};