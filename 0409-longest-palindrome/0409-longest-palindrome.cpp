class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();

        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }

        int evenlength = 0;
        int hasOdd = false;
        int oddlength = 0;

        for(auto i = mp.begin(); i != mp.end(); i++){
            if(i->second % 2 == 0)
            {
                evenlength += i->second;  // Add even frequencies fully
            }
            else
            {
                hasOdd = true; // Mark that there is an odd frequency
                oddlength += i->second - 1;  // Add the largest even part of odd frequencies

            }
        }

        return (evenlength + oddlength + (hasOdd == true ? 1:0));
        
    }
};


/*
class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();

        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }

        int evn = 0;
        int odd = 0;
        int oddlength = 0;

        for(auto i = mp.begin(); i != mp.end(); i++){
            if(i->second % 2 ==0){
                evn += i->second;
            }
            else{
                if(i->second > 1){
                    oddlength = i->second;
                }
                else
                    odd++;
            }
        }

        return evn + (odd > 0 ? 1 : 0) + oddlength;
        
    }
};

*/

/*
ccc

bananas
a = 3
b = 1
n = 2
s = 1

abccccdd

a = 1
b = 1
c = 4
d = 2

*/