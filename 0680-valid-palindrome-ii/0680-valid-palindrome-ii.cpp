class Solution {
public:
    bool validPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }

    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};